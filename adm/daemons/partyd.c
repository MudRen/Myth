#ifndef FAMILY_D
#define FAMILY_D __DIR__"familyd"
#endif
// partyd.c

#include <ansi.h>

#pragma optimize

inherit F_SAVE;
inherit F_DBASE;

// 帮派声望最大是10亿
#define MAX_PARTY_FAME         1000000000

// 每个帮派最多有100个仇人
#define MAX_HATRED_PERSON   100

// 当仇人超过的时候每次移除多少个
#define HATREDP_REMOVED     10

mapping party_fame;
mapping last_party_fame;

// 帮派对仇人仇恨度的排序
protected int sort_hatred(string id1, string id2, mapping hatred);

void create()
{
    seteuid(getuid());
    restore();
    set_heart_beat(1800 + random(30));
    if (! mapp(party_fame)) party_fame = ([ ]);
}

void remove()
{
    save();
}

public void mud_shutdown()
{
    save();
}

// 心跳：维护帮派的通常信息
protected void heart_beat()
{
    int t;
    int last;
    string *all_fam;
    string fam;

    t = time();
    last = query("last_check");
    if ((t / 86400) != (last / 86400))
    {
        // 天数发生了变化：复制帮派的名望信息
        all_fam = keys(party_fame) - ({ 0 });
        last_party_fame = ([ ]);

        foreach (fam in all_fam)
            last_party_fame[fam] = party_fame[fam];
    }
    set("last_check", t);

    // 保存帮派的最新信息
    save();
}

// 返回帮派声望：如果参数为空，返回mapping类型，包含了所有同
// 盟的声望；如果参数是人物， 则返回该人物所在的那个帮派的声
// 望；如果参数是帮派，则返回该帮派的声望。
public mixed query_party_fame(mixed ob)
{
    string fname;

    if (stringp(ob))
        return party_fame[ob];

    if (objectp(ob))
    {
        if (stringp(fname = ob->query("party/party_name")))
            return party_fame[fname];
        else
            return 0;
    }

    return party_fame;
}

// 查询昨天的帮派名望信息
public mapping query_all_last_party_fame()
{
    if (! mapp(last_party_fame))
        // 没有昨天的信息，返回今天的
        return party_fame;

    // 返回昨天的帮派声望信息
    return last_party_fame;
}

// 查询帮派的仇恨信息：输入的ob可以是帮派的名字，也可是帮派
// 中的人物。
public mapping query_party_hatred(mixed ob)
{
    mapping hatred;
    string fname;

    if (objectp(ob))
        fname = ob->query("party/party_name");
    else
    if (stringp(ob))
        fname = ob;
    else
        fname = 0;

    if (! stringp(fname) || ! mapp(hatred = query(fname + "/hatred")))
        return 0;

    return hatred;
}

// 变化帮派声望：输入的ob可以是帮派的名字，也可是帮派中的人
// 物。
public void add_party_fame(mixed ob, int n)
{
    int new_fame;
    string fname;

    if (objectp(ob))
        fname = ob->query("party/party_name");
    else
    if (stringp(ob))
        fname = ob;
    else
        fname = 0;

    if (! stringp(fname) || undefinedp(query(fname + "/member")))
        return;

    // 计算新的帮派声望
    new_fame = party_fame[fname] + n;
    if (new_fame < 0) new_fame = 0;
    if (new_fame > MAX_PARTY_FAME)
        new_fame = MAX_PARTY_FAME;
    party_fame[fname] = new_fame;
}

// 帮派间仇杀
public void party_kill(object killer, object victim)
{
    int kexp;
    int vexp;
    string vfam;
    string kfam;
    string kid;
    int fame_delta;
    mapping hatred;
    mixed *d;

    // 只有玩家之间的仇杀才计算在内
    if (! objectp(killer) || ! playerp(killer) ||
        ! objectp(victim) || ! playerp(victim))
        return;

    // 巫师之间的比划可不能算数
    if (wizardp(killer) || wizardp(victim))
        return;

    // 查看这两个玩家所处的结义帮派
    kfam = killer->query("party/party_name");
    vfam = victim->query("party/party_name");

    if (killer->is_brother(victim) && killer->is_killing(victim->query("id")))
        // 杀死结拜兄弟，威望降低10%
        killer->add("weiwang", -killer->query("weiwang") / 10);

    if (! stringp(kfam) && ! stringp(vfam))
        // 都不在帮派内，不必继续了
        return;

    kexp = killer->query("combat_exp");
    vexp = victim->query("combat_exp");

    if (kfam == vfam)
    {
        if (! killer->is_killing(victim->query("id")))
            // 失手所杀，不予理会
            return;

        // 兄弟间残杀？不与理会，直接扣除联盟和个人1/10威望。
        add_party_fame(kfam, -party_fame[kfam] / 10);
        killer->add("weiwang", -killer->query("weiwang") / 10);
        return;
    }

    if (kexp < vexp * 3 && vexp >= 100000)
    {
        // 杀手的经验不是远远的大于对方，并且被杀的
        // 人有一定的经验，这将导致帮派声望的降低。
        fame_delta = vexp + killer->query("score") * 2 +
                 killer->query("weiwang") * 10;
        fame_delta /= 1000;
    } else
        // 对手经验太少，或是差距太大，不影响声望
        fame_delta = 0;

    // 查看杀手所在的帮派是否仇恨死者：如果仇恨，则能够
    // 带动声望的变化。
    if (stringp(kfam))
    {
        string path;

        path = kfam + "/hatred/"+ victim->query("id");
        d = query(path);
        if (arrayp(d) && sizeof(d) >= 2 && intp(d[1]))
        {
            // 仇恨死者，帮派获得额外的声望
            if (d[1] > 2000)
                CHANNEL_D->do_channel(this_object(), "rumor",
                    "听说" + killer->name(1) + "击毙了" +
                    victim->name(1) + "，为" +
                    kfam + "出了一口恶气。");
            fame_delta += d[1] / 3;

            // 对此人的仇恨降低(降低的要比增加的要多)，
            // 具体可以看fame_delta 与仇恨度公司的差异
            d[1] -= fame_delta;
            if (d[1] <= 0)
                delete(path);
            else
                set(path, d);
        }
    }

    // 调整两个帮派的声望
    add_party_fame(killer,  fame_delta);
    add_party_fame(victim, -fame_delta);

    // 统计该杀手对本门的残害程度
    if (! stringp(vfam))
        return;

    // 仇恨程度和声望的变化都是在一个数量级上(K经验)，但
    // 是仇恨程度低于声望的变化。
    vexp = vexp / 1000 + 1;
    if (vexp > 5000)
        vexp = (vexp - 5000) / 16 + 2000;
    else
    if (vexp > 1000)
        vexp = (vexp - 1000) / 4 + 1000;

    kid = killer->query("id");
    if (! mapp(hatred = query(vfam + "/hatred")))
    {
        set(vfam + "/hatred/" + kid,
            ({ killer->name(), vexp }));
        return;
    }

    // 每个帮派最多记录若干个仇人
    if (! undefinedp(d = hatred[kid]))
    {
        if (! arrayp(d) || sizeof(d) < 2 ||
            ! intp(d[1]) || ! stringp(d[0]))
        {
            // 这个ID的数据出了故障
            d = 0;
        }
    } else
    if (sizeof(hatred) >= MAX_HATRED_PERSON)
    {
        string *ids;
        int i;

        // 过滤去掉一些人，为什么不去掉一个？这是为
        // 了防止过滤频繁的进行过滤操作。
        ids = sort_array(keys(hatred),
                 (: sort_hatred :), hatred);
        for (i = 0; i < sizeof(ids) && i < HATREDP_REMOVED; i++)
            map_delete(hatred, ids[i]);
    }

    if (! arrayp(d))
        d = ({ killer->name(1), vexp });
    else
    {
        d[0] = killer->name(1);
        d[1] += vexp;
    }

    // 记录这个人的信息
    hatred[kid] = d;
}

// 去掉所有帮派对某个人的仇恨信息
public void remove_hatred(string id)
{
    mapping dbase, party, hatred;
    string fam;

    if (! mapp(dbase = query_entire_dbase()))
        // 现在还没有仇恨信息
        return;

    // 查阅所有的帮派
    foreach (fam in keys(dbase))
    {
        reset_eval_cost();

        if (! mapp(party = dbase[fam]))
            continue;

        if (mapp(hatred = party["hatred"]))
            // 去掉该帮派对某人的仇恨信息
            map_delete(hatred, id);

        if (! mapp(hatred) || sizeof(hatred) < 1)
            // 这个帮派已经没有仇恨信息
            map_delete(party, "hatred");
    }

    save();
}

// 查看是否可以创建这个帮派
public mixed valid_new_party(string fname)
{
	string *end_name = ({"帮", "会", "楼", "谷"});

    if (query(fname + "/member"))
        return "人家早就有叫这个的啦，你就别凑热闹了。\n";

    if (! undefinedp(FAMILY_D->query_family_fame(fname)))
        return "江湖赏已经有" + fname + "了，你还想做什么？\n";
        
    if (member_array(fname[<2..<1], end_name) == -1)
        return "帮派类型只能是「帮、 会、 楼、 谷」之一！\n";
    return 0;
}

// 创建帮派
public void create_party(string fname, object leader, int base, object *obs)
{
    mapping party;
    string *channels;
    object ob;

    party_fame[fname] = base;
    if (! mapp(last_party_fame))
        last_party_fame = ([ fname : base ]);
    else
        last_party_fame[fname] = base;

    set(fname, ([ "member" : obs->query("id"),
                  "leader" : leader->query("id"),
                  "time"   : time() ]));
    save();

    foreach (ob in obs)
    {
        party = ([ "time"          : time(),
                   "party_name"    : fname,
                   "party_level"   : 10 
                ]);
        ob->set("party", party);
        if (ob == leader)
            ob->set("party/party_level", 0);
        channels = ob->query("channels");
        if (! arrayp(channels) || ! sizeof(channels))
            channels = ({ "party" });
        else
        if (member_array("party", channels) == -1)
            channels += ({ "party" });

        ob->set("channels", channels);
        ob->save();
    }
}

// 解散帮派
public void dismiss_party(string fname)
{
    string *ids;
    string id;

    // 清除名望信息
    map_delete(party_fame, fname);
    if (mapp(last_party_fame)) map_delete(last_party_fame, fname);

    // 清除帮派中的所有玩家的相关信息
    ids = query(fname + "/member");

    if (arrayp(ids))
    {
        // 帮派中还有玩家，清除他们的信息
        foreach (id in ids)
        {
            // 处理中
            reset_eval_cost();
            UPDATE_D->clear_user_data(id, "party");
        }
    }

    // 清除帮派的所有信息
    delete(fname);
}

// 查询帮派中的弟兄
public string *query_members(mixed ob)
{
    string *member;
    string fname;

    if (objectp(ob))
        fname = ob->query("party/party_name");
    else
    if (stringp(ob))
        fname = ob;
    else
        fname = 0;

    if (! stringp(fname) || ! arrayp(member = query(fname + "/member")))
        return 0;

    return member;
}

// 从帮派中去掉一个人
public varargs void remove_member_from_party(mixed fname, string id)
{
    mapping party;
    string *member;

    if (objectp(fname))
    {
        // fname is user object
        id = fname->query("id");
        if (! stringp(fname = fname->query("party/party_name")))
            return;
    } else
    if (! stringp(fname))
        // or fname must be a party name
        return;

    if (! mapp(party = query(fname)) ||
        ! arrayp(member = party["member"]))
        // no such party or no member in the party
        return 0;

    member -= ({ id, 0 });
    if (sizeof(member) < 1)
    {
        CHANNEL_D->do_channel(this_object(), "rumor",
            "听说" + fname + "人才凋零，昔日成员尽皆散去，从此江湖再无此字号了。");

        // 清除名望信息
        map_delete(party_fame, fname);
        if (mapp(last_party_fame)) map_delete(last_party_fame, fname);

        // 清除帮派的信息
        delete(fname);
    } else
        party["member"] = member;
}

// 在帮派中增加一个人
public void add_member_into_party(string fname, string id)
{
    string *member;

    if (! arrayp(member = query(fname + "/member")))
        return 0;

    if (member_array(id, member) != -1)
        return 0;

    member += ({ id });
    set(fname + "/member", member);
}

// 排序：升序
protected int sort_hatred(string id1, string id2, mapping hatred)
{
    mixed *d1, *d2;

    if (! arrayp(d1 = hatred[id1]) || sizeof(d1) < 2 || ! intp(d1[1]))
        return -1;

    if (! arrayp(d2 = hatred[id2]) || sizeof(d2) < 2 || ! intp(d2[1]))
        return 1;

    return d1[1] - d2[1];
}

public string query_save_file() { return DATA_DIR "partyd"; }
