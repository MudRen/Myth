// copyskill.c
// created by doing

#include <ansi.h>

inherit F_CLEAN_UP;

private int copy_skill(object me, object ob);
int help();

int main(object me, string arg)
{
        object ob;
        object tob;
        string target;

        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                return 0;

        if (! arg)
        {
                help();
                return 1;
        }

        if (sscanf(arg, "%s to %s", arg, target) == 2)
        {
                if (! objectp(tob = present(target, environment(me))))
                        return notify_fail("����ǰû�� " + target + " ����ˡ�\n");
        } else
                tob = me;

        if (wiz_level(me) <= wiz_level(tob) && me != tob)
                return notify_fail("��ֻ�ܸ�Ȩ�ޱ��Լ��͵��˸����书��\n");

        if (arg == "me")
                ob = me;
        else
        if (! objectp(ob = present(arg, environment(me))))
                return notify_fail("����ǰû�� " + arg + " ����ˡ�\n");

        if (! wizardp(me))
                return notify_fail("ֻ����ʦ�ſ��Ը��Ʊ��˵��书��\n");

        if (! is_root(me) && playerp(tob) && ! wizardp(tob))
                return notify_fail("ֻ��������ܸ���ͨ��Ҹ����书��\n");

        if (ob == tob)
                return notify_fail("����Ҫ���ưɡ�\n");

        if (me != tob)
                log_file("static/copyskill", sprintf("%s %s copy %s(%s)'s skill to %s(%s).\n",
                                                     log_time(), log_id(me),
                                                     ob->name(1), ob->query("id"),
                                                     tob->name(1), tob->query("id")));

        copy_skill(tob, ob);
        message_vision(HIM + me->name(1) + HIM "���������дʣ�ֻ��һ�����������$N"
                       HIM "��$n" HIM "��\n" NOR, tob, ob);
        return 1;
}

private int copy_skill(object me, object ob)
{
        mapping hp_status, skill_status, map_status, prepare_status;
        mapping my;
        string *sname, *mname, *pname;
        int i, temp;

        if (mapp(skill_status = me->query_skills()))
        {
                skill_status = me->query_skills();
                sname = keys(skill_status);

                temp = sizeof(skill_status);
                for (i = 0; i < temp; i++)
                        me->delete_skill(sname[i]);
        }

        if (mapp(skill_status = ob->query_skills()))
        {
                skill_status = ob->query_skills();
                sname = keys(skill_status);

                for (i = 0; i < sizeof(skill_status); i++)
                        me->set_skill(sname[i], skill_status[sname[i]]);
        }
        
        if (mapp(map_status = me->query_skill_map()))
        {
                mname = keys(map_status);

                temp = sizeof(map_status);
                for (i = 0; i < temp; i++)
                        me->map_skill(mname[i]);
        }

        if (mapp(map_status = ob->query_skill_map()))
        {
                mname = keys(map_status);

                for(i = 0; i < sizeof(map_status); i++)
                        me->map_skill(mname[i], map_status[mname[i]]);
        }

        if (mapp(prepare_status = me->query_skill_prepare()))
        {
                pname = keys(prepare_status);

                temp = sizeof(prepare_status);
                for(i = 0; i < temp; i++)
                        me->prepare_skill(pname[i]);
        }

        if (mapp(prepare_status = ob->query_skill_prepare()))
        {
                pname = keys(prepare_status);

                for(i = 0; i < sizeof(prepare_status); i++)
                        me->prepare_skill(pname[i], prepare_status[pname[i]]);
        }

        hp_status = ob->query_entire_dbase();
        my = me->query_entire_dbase();

        my["str"] = hp_status["str"];
        my["int"] = hp_status["int"];
        my["con"] = hp_status["con"];
        my["dex"] = hp_status["dex"];

        my["max_kee"]       = hp_status["max_kee"];
        my["eff_kee"]       = hp_status["eff_kee"];
        my["kee"]           = hp_status["kee"];
        my["max_sen"]       = hp_status["max_sen"];
        my["eff_sen"]       = hp_status["eff_sen"];
        my["sen"]           = hp_status["sen"];
        my["max_force"]     = hp_status["max_force"];
        my["force"]         = hp_status["force"];
        my["max_mana"]      = hp_status["max_mana"];
        my["force_factor"]  = hp_status["force_factor"];
        my["mana_factor"]   = hp_status["mana_factor"];
        my["combat_exp"]    = hp_status["combat_exp"];
        my["daoxing"]       = hp_status["daoxing"];

        me->reset_action();
        return 1;
}

int help()
{
        write(@TEXT
ָ���ʽ��copyskill <����> [to <Ŀ�Ķ���>]

���ָ�����㸴�ƶ����ս����������е��书���ܡ�

TEXT );
        return 1 ;
}

