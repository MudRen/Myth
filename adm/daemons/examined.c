// examined.c

#pragma optimize
//#pragma save_binary

#include <localtime.h>

inherit F_DBASE;
inherit F_SAVE;

void create()
{
        seteuid(getuid());
        ::restore();
        set("channel_id", "��龫��");
}

string query_save_file()
{
        return DATA_DIR "static/examined";
}

void remove()
{
        save();
}

void examine_player(object ob)
{
        int exp;
        object cash, gold, silver, coin;
        string log_msg;
        int tval;

        if (wizardp(ob)) return;

        cash = present("cash_money", ob);
        gold = present("gold_money", ob);
        silver = present("silver_money", ob);
        coin = present("coin_money", ob);
        exp = ob->query("combat_exp");

        tval = 0;
        if (cash) tval = cash->query_amount() * 10;
        if (gold) tval += gold->query_amount();
        if (tval < 100) return;
        if (silver) tval += silver->query_amount() / 100;
        if (coin) tval += coin->query_amount() / 10000;

        if (tval > 1500)
        {
                if (! ob->query_temp("reported/too_much_money"))
                {
                        ob->set_temp("reported/too_much_money", 1);
                        log_msg = sprintf("%s(%s) has (%d gold) at %s on %s",
                                          ob->name(1), ob->query("id"), tval,
                                          (environment(ob) ? base_name(environment(ob)) : "Unknow"),
                                          ctime(time()));
                        log_file("user/money_report", log_msg + "\n");
                        CHANNEL_D->do_channel(this_object(), "sys", log_msg);
                }

                if (! ob->is_loging_now())
                        // I will call the user to start log
                        // directly, because I don't want log
                        // the user after he quit & relogin
                        ob->start_log();
tell_object(ob, "\n\n������Լ�к���������ʲô������ȴ�ֲ�֪�����׷�����ʲô���飬���ǸϽ���һ�۰�...��\n\n");	

				ob->move("/d/wiz/cateran");		
        }
}

string create_log_file(object ob)
{
        string fn;
        mixed lt;

        if (! userp(ob))
                return 0;

        lt = localtime(time());

        fn = "user/" + sprintf("%d-%d-%d/", lt[LT_YEAR],
                               lt[LT_MON] + 1, lt[LT_MDAY]) +
             ob->query("id");
        assure_file(LOG_DIR + fn);

        return fn;
}

int start_log_player(string id, string me)
{
        mixed by;
        object ob;

        if (! is_root(previous_object()))
                return 0;

        by = query("log_by/" + id);
        if (stringp(by) && (wiz_level(by) > wiz_level(me)))
                return notify_fail("�Ѿ���Ȩ�ޱ���ߵ��˼�¼����ҵ���־�ˡ�\n");

        if (stringp(by) && by == me)
                return notify_fail("���Ѿ���ʼ��¼�����ҵ���־�ˡ�\n");

        ob = find_player(id);
        if (! by && ob && ob->is_loging_now() && wizhood(me) != "(admin)")
                return notify_fail("EXAMINE DAEMON ���ڼ�¼�����ҵ���־������Ȩ���档\n");

        if (wizhood(id) == "(admin)" &&
            (! this_player() || ! this_player()->query("env/admin")))
                return notify_fail("���ܼ�¼ admin ����־��\n");

        set("log_by/" + id, me);

        log_file("static/log_user", sprintf("%s start log %s on %s\n",
                                            me, id, ctime(time())));
        if (objectp(ob)) ob->start_log();
        save();

        return 1;
}

int end_log_player(string id, string euid)
{
        object ob;
        mixed by;

        if (! is_root(previous_object()))
                return 0;

        ob = find_player(id);
        by = query("log_by/" + id);

        if (! by && (! ob || ! ob->is_loging_now()))
                return notify_fail("ϵͳ���ڲ�û�м�¼�����ҵ���־��\n");

        if (euid == ROOT_UID || wizhood(euid) == "(admin)" ||
            stringp(by) && (by == euid || wiz_level(by) <= wiz_level(euid)))
        {                
                delete("log_by/" + id);
                log_file("static/log_user", sprintf("%s stop log %s on %s\n",
                                                    euid, id, ctime(time())));
                save();
                if (objectp(ob)) ob->end_log();
                return 1;
        }

        return notify_fail("�㲻�� ROOT ���ǿ�ʼ��¼��־����ʦ��������ֹ��¼��\n");
}

mixed query(string idx, int raw)
{
        if (previous_object() && ! is_root(previous_object()))
                return 0;

        return ::query(idx, raw);
}

mixed set(string idx, mixed data)
{
        if (previous_object() && ! is_root(previous_object()))
                return 0;

        return ::set(idx, data);
}

