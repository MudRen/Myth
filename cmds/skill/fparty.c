// party.c

#include <ansi.h>
#include <getconfig.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int sort_hatred(string id1, string id2, mapping hatred);
int sort_member(string id1, string id2);
int show_party_info(object me, string arg);
int show_party_member(object me, string arg);
int show_party_hatred(object me, string arg);
int dismiss_party(object me, string arg);

int main(object me, string arg)
{
        object *obs;
        string fname;
        string *args;

        if (! arg) arg = "info";
        args = explode(arg, " ");
        if (sizeof(args) > 1)
                arg = implode(args[1..<1], " ");
        else
                arg = 0;

        switch (args[0])
        {
        case "info":
                // 显示帮派的信息
                return show_party_info(me, arg);

        case "member":
                return show_party_member(me, arg);

        case "dismiss":
                return dismiss_party(me, arg);

        case "top":
                return __DIR__"top"->main(me, "party");

        case "hatred":
                // 显示帮派的仇人
                return show_party_hatred(me, arg);

        case "out":
                if (! stringp(fname = me->query("party/party_name")))
                        return notify_fail("你现在还没有加入任何帮派呢。\n");

                if (me->query_temp("pending/out_party"))
                {
                        // 帮派的声望下降
                        PARTY_D->add_party_fame(fname, -PARTY_D->query_party_fame(fname) / 10);
                        CHANNEL_D->do_channel(this_object(), "rumor",
                                "听说" + me->name(1) + "(" + me->query("id") +
                                ")义无反顾，已经背离" + fname + "而去。");
                        me->delete_temp("pending/out_party");

                        // 清除该用户在帮派中的信息
                        UPDATE_D->clear_user_data(me->query("id"), "party");
                        return 1;
                }

                write("你真的想要背弃当初的结义好友吗？这样做会降低" + fname + "的声望。\n"
                      YEL "如果你确定了，就再输入一次 fparty out 命令。\n" NOR);
                me->set_temp("pending/out_party", 1);
                return 1;
        }

        write("无效的参数。\n");
        return 1;
}

// 根据玩家和参数选择帮派的名字
mixed select_party(object me, string arg)
{
        string fam;
        object ob;

        if (! wizardp(me))
                // only wizard can show every party's list
                fam = 0;
        else
        if (stringp(arg) && arg != "")
        {
                if (! arrayp(PARTY_D->query("member/" + fam)))
                        fam = 0;
                else
                        fam = arg;

                if (! stringp(fam) && objectp(ob = UPDATE_D->global_find_player(arg)))
                {
                        // 没有 arg 这个帮派，查看是否有该玩家
                        fam = ob->query("party/party_name");
                        UPDATE_D->global_destruct_player(ob);
                        if (! stringp(fam))
                                return notify_fail("这人现在没有和别人结成帮派。\n");
                }

                if (! stringp(fam))
                        return notify_fail("没有这个玩家，不能查阅相关的帮派。\n");
        }

        if (! fam)
        {
                // select my party
                if (! stringp(fam = me->query("party/party_name")))
                        return notify_fail("你现在还没有加入任何帮派呢。。\n");
        }

        return fam;
}

// 显示帮派的仇人
int show_party_hatred(object me, string arg)
{
        mapping hatred;
        string fam;
        string *ids;
        mixed *data;
        string msg;
        string st;
        int count;
        int i;

        if (! stringp(fam = select_party(me, arg)))
                return 0;

        hatred = PARTY_D->query_party_hatred(fam);
        if (! mapp(hatred) || ! sizeof(hatred))
        {
                write(fam + "现在没有什么仇人。\n");
                return 1;
        }

        ids = keys(hatred) - ({ 0 });
        ids = sort_array(ids, (: sort_hatred :), hatred);

        count = 0;
        msg = WHT "目前" + fam + "在江湖上的仇敌都有\n" NOR
              HIY "────────────────\n" NOR;
        for (i = 0; i < sizeof(ids) && count < 30; i++)
        {
                data = hatred[ids[i]];
                if (! arrayp(data) || sizeof(data) < 2 ||
                    ! stringp(data[0]) || ! intp(data[1]))
                        continue;

                st = sprintf("%s(%s%s%s)", data[0], YEL, ids[i], NOR);
                msg += sprintf("%2d. %-34s  %s%-9d%s\n",
                               ++count, st, HIR, data[1], NOR);
        }

        msg += HIY "────────────────\n" NOR;
        if (i < sizeof(ids))
                msg += WHT "江湖上的敌人太多，难以尽数。\n" NOR;
        else
                msg += WHT "目前一共是" + chinese_number(i) +
                       "人。\n" NOR;
        write(msg);
        return 1;
}

// 显示某一个帮派中的人员
int show_party_member(object me, string arg)
{
        string *member;
        string id;
        object user;
        string msg;
        int n;

        if (! arg)
        {
                if (! stringp(arg = me->query("party/party_name")))
                        return notify_fail("你现在还没有加入任何一个帮派呢。\n");
        }

	if (! arrayp(member = PARTY_D->query_members(arg)))
        {
                write("现在江湖上没有(" + arg + ")这个字号。\n");
                return 1;
        }

        if (sizeof(member) < 1)
                return notify_fail(arg + "现在人丁稀落。\n");

        if (! wizardp(me))
        {
                if (me->query("jing") < 50)
                        return notify_fail("你现在精神不济，无法打听这些消息。\n");

                if (me->is_busy())
                        return notify_fail("你现在正忙，没有时间打听这些消息。\n");

                me->receive_damage("jing", 50);
                me->start_busy(3);
        }

        msg = "";
        n = 0;
        foreach (id in member)
        {
                user = UPDATE_D->global_find_player(id);
                if (! objectp(user))
                        continue;

                n++;
                msg += user->short(1) + "\n";
                UPDATE_D->global_destruct_player(user);
        }

        if (msg == "")
                return notify_fail(arg + "现在人丁稀落。\n");

        write(arg + "目前有以下" + chinese_number(n) + "人：\n" + msg);
        return 1;
}

// 显示帮派中的信息
int show_party_info(object me, string arg)
{
        string fam;
        object  ob;
        string  msg;
        string pro;
        string *member;
        string  id;

        if (! stringp(fam = select_party(me, arg)))
                return 0;

        if (fam == me->query("party/party_name"))
                pro = "你";
        else
                pro = fam;

	if (! arrayp(member = PARTY_D->query_members(fam)))
        {
                write("现在江湖上没有(" + fam + ")这个字号。\n");
                return 1;
        }

        if (sizeof(member) < 1)
                return notify_fail(pro + "现在没有一个成员。\n");

        msg = pro + "现在" + LOCAL_MUD_NAME() + "的帮派成员都有：\n\n";
        member = sort_array(member, (: sort_member :));
        foreach (id in member)
        {
                msg += sprintf(WHT "%-10s  ", id);
                if (objectp(ob = find_player(id)))
                        msg += sprintf(HIY "在线   "
                                       NOR WHT "经验：" HIC "%-9d "
                                       NOR WHT "阅历：" HIW "%-8d "
                                       NOR WHT "威望：" HIY "%-8d\n" NOR,
                                       ob->query("combat_exp"),
                                       ob->query("score"),
                                       ob->query("weiwang"));
                else
                        msg += HIR "不在线\n" NOR;
        }

        msg += sprintf("\n现在%s中一共有%s位帮派成员，在江湖上具有 %s%d%s 点声望。\n",
                       fam, chinese_number(sizeof(member)),
                       HIY, PARTY_D->query_party_fame(fam), NOR);
        write(msg);

	return 1;
}

// 显示某一个帮派中的人员
int dismiss_party(object me, string arg)
{
        string *member;
        string id;
        object user;
        string msg;
        int n;

        if (wiz_level(me) < wiz_level("(arch)"))
                return notify_fail("你的权限不够，不能强行解散帮派。\n");

        if (! arg)
                return notify_fail("你要解散哪个帮派？\n");

	if (! arrayp(member = PARTY_D->query_members(arg)))
        {
                write("现在江湖上没有(" + arg + ")这个字号。\n");
                return 1;
        }

        write("你强行解散了" + arg + "。\n");
        PARTY_D->dismiss_party(arg);
        return 1;
}


// 给所有的仇恨对象排序
int sort_hatred(string id1, string id2, mapping hatred)
{
        mixed *d1, *d2;

        if (! arrayp(d1 = hatred[id1]) || sizeof(d1) < 2 || ! intp(d1[1]))
                return 1;

        if (! arrayp(d2 = hatred[id2]) || sizeof(d2) < 2 || ! intp(d2[1]))
                return -1;

        return d2[1] - d1[1];
}

// 给帮派中的所有结义成员排序
int sort_member(string id1, string id2)
{
        object ob1, ob2;

        ob1 = find_player(id1);
        ob2 = find_player(id2);
        if (! objectp(ob1) && ! objectp(ob2))
                return strcmp(id2, id1);

        if (objectp(ob1) && objectp(ob2))
                return ob2->query("combat_exp") - ob1->query("combat_exp");

        if (objectp(ob1))
                return -1;

        return 1;
}

int help(object me)
{
   	write(@HELP
指令格式: fparty info [玩家] | hatred [玩家] | member [帮派名字] | top

查看目前你结义的帮派的各种信息，其中：

info   ：查看帮派中的人物，成员状态，声望。
hatred ：查看帮派的仇恨对象。
member ：查看某个帮派的成员。
top    ：查看结义帮派的声望排名。

巫师可以查看各个帮派的信息，只需要在命令后面加上帮派的名字或
是帮派中的玩家。另外巫师可以使用 fparty dismiss 命令强行解散
一个帮派。

see also: team (团体帮派)
HELP );
   	return 1;
}
