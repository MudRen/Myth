// promote.c
// modify by mudring

#include <ansi.h>

inherit F_CLEAN_UP;

// check the valid levels.
mapping valid_level = ([ //
        "admin"         :       "(admin)",
        "arch"          :       "(arch)",
        "wizard"        :       "(wizard)",
        "apprentice"    :       "(apprentice)",
        "immortal"      :       "(immortal)",
        "player"        :       "(player)",
]);

int main(object me, string arg)
{
        object ob;
        string old_status, new_status;
        string* rights;
        int i, pass;
        rights = keys(valid_level);

        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;

// 29  return notify_fail("��������� ok???? :)\n");
        if (! arg || sscanf(arg, "%s %s", arg, new_status) != 2)
                return notify_fail("ָ���ʽ��promote <ʹ����> <�ȼ�>\n");

        if (wiz_level(new_status) < 0) return notify_fail("û�����ֵȼ���\n");

        // checking the valid levels
        for(i=0; i < sizeof(rights); i++) {
                if (new_status == rights[i]) {
                        new_status = valid_level[rights[i]];
                        pass = 1; // valid new level setting.
                }
        }

        // invalid new level setting.
        if( !pass ) return notify_fail("û�����ֵȼ���\n");

        ob = UPDATE_D->global_find_player(arg);

        if (! objectp(ob)) // no this player
                return notify_fail("��ֻ�ܸı�ʹ���ߵ�Ȩ�ޡ�\n");

        if (ob == me) { // this player is myself
                UPDATE_D->global_destruct_player(ob, 1);
                write("�㲻�ܸı��Լ���Ȩ�ޡ�\n");
                return 1;
        }

        if (wiz_level(me) <= wiz_level(new_status) ||
            wiz_level(me) < wiz_level(ob)) { // my level < new level
                UPDATE_D->global_destruct_player(ob, 1);
                write("��û������Ȩ����\n");
                return 1;
        }

        old_status = wizhood(ob);
        seteuid(getuid());

        if( old_status == new_status ){
                UPDATE_D->global_destruct_player(ob, 1);
                write("�����ڣ���\n");
                return 1;
        }

        if (! (SECURITY_D->set_status(ob, new_status))) {
                UPDATE_D->global_destruct_player(ob, 1);
                write("�޸�ʧ�ܡ�\n");
                return 1;
        }

        message_vision("$N��$n��Ȩ�޴� " + old_status + " ��Ϊ " + new_status + " ��\n", me, ob);
        log_file("static/promote",
                  getuid(me) + " promoted " + getuid(ob) + " to " + new_status
                  + " on " + log_time() + "��\n" );
        if (new_status != "(player)")
                EXAMINE_D->start_log_player(ob->query("id"), "root");
        seteuid(getuid());
        ob->setup();

        UPDATE_D->global_destruct_player(ob, 1);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ�� promote ����<id> ����<level>

��������Ȩ�޵ȼ��� player��immortal��apprentice��wizard��
arch��admin��
һ�� admin ������Ȩ�����κεȼ�, �� arch ֻ�������� arch��
ע�⣺���ڿ��Է�����������������ע��ʹ�ã�
HELP );
    return 1;
}

