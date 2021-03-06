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

// 29  return notify_fail("商议后再用 ok???? :)\n");
        if (! arg || sscanf(arg, "%s %s", arg, new_status) != 2)
                return notify_fail("指令格式：promote <使用者> <等级>\n");

        if (wiz_level(new_status) < 0) return notify_fail("没有这种等级。\n");

        // checking the valid levels
        for(i=0; i < sizeof(rights); i++) {
                if (new_status == rights[i]) {
                        new_status = valid_level[rights[i]];
                        pass = 1; // valid new level setting.
                }
        }

        // invalid new level setting.
        if( !pass ) return notify_fail("没有这种等级。\n");

        ob = UPDATE_D->global_find_player(arg);

        if (! objectp(ob)) // no this player
                return notify_fail("你只能改变使用者的权限。\n");

        if (ob == me) { // this player is myself
                UPDATE_D->global_destruct_player(ob, 1);
                write("你不能改变自己的权限。\n");
                return 1;
        }

        if (wiz_level(me) <= wiz_level(new_status) ||
            wiz_level(me) < wiz_level(ob)) { // my level < new level
                UPDATE_D->global_destruct_player(ob, 1);
                write("你没有这种权力。\n");
                return 1;
        }

        old_status = wizhood(ob);
        seteuid(getuid());

        if( old_status == new_status ){
                UPDATE_D->global_destruct_player(ob, 1);
                write("白折腾？。\n");
                return 1;
        }

        if (! (SECURITY_D->set_status(ob, new_status))) {
                UPDATE_D->global_destruct_player(ob, 1);
                write("修改失败。\n");
                return 1;
        }

        message_vision("$N将$n的权限从 " + old_status + " 改为 " + new_status + " 。\n", me, ob);
        log_file("static/promote",
                  getuid(me) + " promoted " + getuid(ob) + " to " + new_status
                  + " on " + log_time() + "。\n" );
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
指令格式： promote 人物<id> 级别<level>

用来提升权限等级， player，immortal，apprentice，wizard，
arch，admin。
一个 admin 能提升权限至任何等级, 而 arch 只能提升至 arch。
注意：由于可以非在线提升，所以请注意使用！
HELP );
    return 1;
}

