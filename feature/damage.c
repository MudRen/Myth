// damage.c
// Optimized by mudring@SanJie

#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>

void remove_faint(object me);

int ghost = 0;

int is_ghost() { return ghost; }

// the three following function.
// are no use in us mud.
// mudring Dec/05/2002
int self_purge()
{

    object me = this_object();
    object link_ob = me->query_temp("link_ob");

    if (!userp(me)) return 0;

    if ((int)me->query("max_kee") > 0
        && (int)me->query("max_sen") > 0 ) return 0;
    set_heart_beat(0);
    ghost =1;
    me->move("/d/death/block.c");
    CHANNEL_D->do_channel(me, "rumor", me->query("name")
        + "��Ϊ���̫���������ᣬ�����������ǣ���Զ�뿪�����ǣ�");

    return 1;
}

void gameover()
{

    object me = this_object();

    //currently, only move the player to /d/death/block.c
    if (!userp(me)) return;


    me->move("/d/death/block.c");
    if (!me->query("life/death_announced"))
    {
        me->set("life/death_announced", 1);
        CHANNEL_D->do_channel(load_object(COMBAT_D), "rumor", me->query("name")
            + "�������ޣ���Զ���뿪�����ǡ�");
    }

}

int check_gameover()
{

    object me = this_object();
    return 0;

    if (wizardp(me)) return 0;
    if (!userp(me)) return 0;

    if ((me->query("age") <= me->query("life/life_time"))
        || me->query("life/live_forever")) return 0;

    gameover();

    return 1;
}

void announce_live_forever(string reason)
{
    object me = this_object();
    object dadi;

    if (!reason) return;

    if (me->query("life/live_forever_announced")) return;

    me->set("life/live_forever_announced", 1);
    me->set("life/live_forever", 1);

    dadi = new("/d/wiz/npc/dadi.c");
    dadi->move(environment(me));

    message_vision(HIY"ֻ��һ��������翣�һ������Ƴ����컺��������\n"NOR, dadi);
    message_vision(HIY"$N�ӳ�������������$nһ���֣���ϲ����ϲ��\n"NOR, dadi, me);
    dadi->command_function("chat "+reason);
    message_vision(HIY"$Nһ���֣��Ƴ�������ȥ...\n"NOR, dadi);
    destruct(dadi);

    return;
}

varargs int receive_damage(string type, int damage, object who,string d_type)
{
    int val, mana, level;

    // ����ϱ����������ˣ����㻹����.
    // mudring Dec/05/2002.
    if (damage < 0) damage = 0;
    if (type != "kee" && type != "sen")
        error("F_DAMAGE: �˺��������( ֻ���� kee, sen ����֮һ )��\n");

    if (who) set_temp("last_damage_from", who);

    if (objectp(who))
    {
        
        if (objectp(who->query_temp("invoker")))
            who = who->query_temp("invoker");
        set_temp("last_damage_from", who);
    }
    if (d_type) damage=PFM_D->do_control(damage,who,d_type,this_object());

    
    mana = 0;
    if (query_temp("apply/manashieldflag") == 1) //use manashield
    {
        val = (int)query("mana");
        mana = val;

        if (mana >= damage * 4)
        {
            set("mana", mana - (damage * 4));
            damage = 0;
        } else
        {
            damage = damage - (mana / 4);
            if (query_temp("apply/manashieldflag") == 1) //use manashield
                set("mana", 0);
        }
    }

    val = (int)query(type) - damage;
    if( val < 0 ) val = -1;
    set(type, val);

    set_heart_beat(1);

    return damage;
}

varargs int receive_wound(string type, int damage, object who)
{
    int val;

    // mudring Dec/05/2002.
    if (damage < 0) damage = 0;
    if (type != "kee" && type != "sen")
        error("F_DAMAGE: �˺��������( ֻ���� kee, sen ����֮һ )��\n");

    if (who) set_temp("last_damage_from", who);
    if (objectp(who))
    {
        if (objectp(who->query_temp("invoker")))
            who = who->query_temp("invoker");
        set_temp("last_damage_from", who);
    }

    val = (int)query("eff_" + type) - damage;
    if (val < 0) val = -1;
    set("eff_" + type, val);

    if ((int)query(type) > val) set(type, val);

    set_heart_beat(1);

    return damage;
}

int receive_heal(string type, int heal)
{
    int val;

    // mudring Dec/05/2002.
    if (heal < 0) heal = 0;
    if (type != "kee" && type != "sen")
        error("F_DAMAGE: �ָ��������( ֻ���� kee, sen ����֮һ )��\n");

    val = (int)query(type) + heal;

    if (val > (int)query("eff_" + type))
        val = (int)query("eff_" + type);
    set(type, val);

    return heal;
}

int receive_curing(string type, int heal)
{
    int max, val;

    // mudring Dec/05/2002.
    if (heal < 0) heal = 0;
    if (type != "kee" && type != "sen")
        error("F_DAMAGE: �ָ��������( ֻ���� kee, sen ����֮һ )��\n");

    val = (int)query("eff_" + type) + heal;
    max = (int)query("max_" + type);

    if (val > max)
        val = max;
    set( "eff_" + type, val);

    return heal;
}

// snowcat feb 8 1998
void remove_ride ()
{
    object rider, ridee;

    if (ridee = query_temp("ridee"))
        ridee->delete_temp("rider");
    delete_temp("ridee");
    add_temp("apply/dodge", -query_temp("ride/dodge"));
    set_temp("ride/dodge", 0);
    if (rider = query_temp("rider"))
        rider->remove_ride();
    delete_temp("rider");
}

// optimize.
// mudring Dec/05/2002
varargs void unconcious(object killby, int flag)
{
    object me;
    object defeater;

    me = this_object();

    if (environment()
        && environment()->query("alternative_die"))
    {
		// �������û�� Bug,�ĵ��˶��ˣ�Ҳ�ͳ��� Bug.
		// mudring Apr/15/2004
		if (!flag)
		{
			me->set_temp("ring_yun", 1);
    	    environment()->alternative_die(me);
        	return;
		}
    }

    if (!living(me)) return;
    if (wizardp(me) && query("env/immortal")) return;
    // mudring Dec/05/2002
    if (me->is_busy()) me->interrupt_me();

    if (objectp(defeater = query_temp("last_damage_from")))
        COMBAT_D->winner_reward(defeater, me);

    me->remove_all_enemy();
    me->set_temp("faint_by", defeater);
    remove_ride();
    // mudring Dec/05/2002
    me->clear_written();

    tell_object(me, HIR "\n��ֻ����ͷ�����ͣ���ǰһ�ڣ�����ʲôҲ��֪���ˡ���\n\n" NOR);
    command("hp");
    me->disable_player(" <���Բ���>");
    set("kee", 0);
    set("sen", 0);
    set_temp("block_msg/all", 1);
    COMBAT_D->announce(me, "unconcious");

    call_out("revive", random(100 - query("con")) + 30);
}

// optimize.
// mudring Dec/05/2002
varargs void revive(int quiet)
{
    object me;
    object env;

    me = this_object();

    remove_call_out("revive");
    env = environment();
    // mudring Dec/05/2002
    if (env)
    {
        while (env->is_character() && environment(env))
            env = environment(env);
        if (env != environment())
            me->move(env);
    }

    delete_temp("no_move");
    delete_temp("no_special");
    if (me->query_temp("faint_by")) me->delete_temp("faint_by");

    // mudring Dec/05/2002
    delete("disable_type");
    delete_temp("disabled");
//    me->enable_player();
    delete_temp("block_msg/all");
    me->write_prompt();
    if (!quiet)
    {
        COMBAT_D->announce(me, "revive");
        tell_object(me, HIY "\n������������������֪��������\n\n" NOR);
        command("hp");
    }

}

// optimize.
// mudring Dec/05/2002
// void die()
varargs void die(object killby, int flag)
{
    object corpse, killer,me, guai;
    object *inv;
    int i;
    string str;
    string faint_by;

    me = this_object();

    if (environment()
        && environment()->query("alternative_die"))
    {
		// �������û�� Bug,�ĵ��˶��ˣ�Ҳ�ͳ��� Bug.
		// mudring Apr/15/2004
		if (!flag)
		{
	        environment()->alternative_die(me);
    	    return;
		}
    }

    if (query_temp("faint_by"))
        faint_by = query_temp("faint_by");

    if (!living(me)) revive(1);
    else delete_temp("faint_by");

    if( is_ghost() ) return;
    if (wizardp(me) && query("env/immortal")) return;

    // mudring Dec/05/2002
    if (me->is_busy()) me->interrupt_me();
    if (faint_by)
        set_temp("faint_by", faint_by);

    COMBAT_D->announce(me, "dead");

    if (me->query("rulaitask/get") &&
        !me->query_condition("no_pk_time"))
    {
        guai = me->query("rulaitask/guai");

        if (objectp(guai) && (guai == me->query_temp("last_damage_from") ||
            guai == me->query_temp("last_opponent")))
        {
            me->set("eff_kee",me->query("max_kee"));
            me->set("eff_sen",me->query("max_sen"));
            me->set("kee",me->query("max_kee")/3);
            me->set("sen",me->query("max_sen")/3);
            me->add("combat_exp",-3000);
            me->add("daoxing",-3000);
            me->add("rulaitask_log/die",1);
            me->delete("rulaitask/get");
            me->set("rulaitask/fail",1);
            str = me->name()+"��"+guai->name()+"ɱ���ˣ��Һ�������ʱ������ȣ��ż��һ����";
            message("channel:rumor",HIM"��"HIW"ҥ�Դ�˵"HIM"��ĳ�ˣ�" + str + "\n"NOR,
                    users());
            log_file("taskdeath",sprintf("[%s] %s is task killed by %s.\n",
                     ctime(time()),me->query("id"),guai->name()));
            remove_ride();
            me->move("/d/qujing/lingshan/daxiong");
            message_vision(HIY"������һ�����ְ�$N�Ļ��Ǵӵظ������˻�������һ�����ֲ�֪����"
                           "�����$N��ʬ��ץ�˻�������������һ�ϣ�Ӳ�����ذ�$N���Ǳƻ����塣\n"NOR,me);
            me->unconcious();
            return;
        }
    }

    // destroy all self-made fabao here
    inv = all_inventory(me);
    for (i=0; i < sizeof(inv); i++)
    {
        if (inv[i]->query("owner_id") == getuid(me))
        {
            tell_object(me, HIB+"�㿴��" + inv[i]->query("name") +
                        HIB + "�ƿն�ȥ��������ʧ����ʣ�����\n"+NOR);
            destruct( inv[i] );
        }
    }

    // ΪʲôҪ����жϣ�
    // û�и�����.
    // mudring Dec/05/2002
    if ((int)me->query("max_kee") > 0
        && (int)me->query("max_sen") > 0)
    {
        if (objectp(killer = query_temp("last_damage_from")))
        {
            set_temp("my_killer", killer->query("id"));
            COMBAT_D->killer_reward(killer, me);

            if (userp(me))
                log_file("death",sprintf("[%s] %s is killed by %s.\n",
                         ctime(time()), getuid(me), killer->query("id")));

        } else
        if (userp(me))
        {
            COMBAT_D->victim_penalty(me);
            // added die_reason and optimize here
            // mudring Sep/26/2002
            if (!str = me->query_temp("death_msg"))
                // can set customized death message to death_msg.
                str = "Ī����������ˡ�";
            me->set("die_reason", str);
            str = me->name(1) + str;
            COMBAT_D->announce(me, "death_rumor", str);
            me->delete_temp("death_msg");
            log_file("death",sprintf("[%s] %s is killed: %s.\n",
                     ctime(time()), getuid(me), str));
        }
    }

    command("hp");
    remove_ride();

    if (objectp(corpse = CHAR_D->make_corpse(me, killer)))
        corpse->move(environment());

    me->remove_all_killer();
    all_inventory(environment())->remove_killer(me);

    me->dismiss_team();
    // if (me->self_purge()) return;

    if (userp(me))
    {
        set("kee", 1);
        set("eff_kee", 1);
        set("sen", 1);
        set("eff_sen", 1);

        // ���漸������ʵ���Ѿ�û���ô�
        // mudring Dec/05/2002
        if (!me->query("life/life_time"))
            me->set("life/life_time", 60);
        if (!me->query("life/no_death_decrease"))
            me->set("life/life_time", (int)me->query("life/life_time") - 1);

        if (check_gameover()) return;

        ghost = 1;
        me->move(DEATH_ROOM);
        DEATH_ROOM->start_death(me);
    }
	else
	{
        destruct(me);
	}
}

void reincarnate()
{
    ghost = 0;
    // ���ʵ�֮һ����Ӧ��������
    // mudring Dec/05/2002
    command("drop all");
    set("eff_kee", query("max_kee"));
    set("eff_sen", query("max_sen"));
}

// �пոĸ�������������.
// ����������Ӧ�ÿ��Դﵽ�ܴ�ķ���.
// mudring Dec/05/2002
int max_food_capacity() { return query("str")*3+query("con")*7; }

int max_water_capacity() { return query("str")*3+query("con")*7; }

// ��������������Ժúù�˼��
// Ӧ�ÿ���д�ĺ�����˼��.
int heal_up()
{
    int update_flag, i;
    mapping my;
    object me;

    me = this_object();

    if(!userp(me) && !me->open_heart_beat())
    {
        set_heart_beat(0);
        return 0;
    }

    if (objectp(environment(me))
        && environment(me)->query("no_time")) return -1;

    update_flag = 0;
    my = query_entire_dbase();

    if (sizeof(query_temp("no_heal_up")))
        return update_flag;

    if (!userp(me)
        && me->is_fighting()
        && !my["allow_heal_up"]) return update_flag;

    if (my["water"] > 0) { my["water"] --; update_flag++; }
    if (my["food"] > 0) { my["food"] --; update_flag++; }

    if (me->is_busy() ) return update_flag;


    if (my["water"] < 1 && userp(me)) return update_flag;

    my["kee"] += my["con"] / 3 + my["force"] / 10;
    if (my["kee"] >= my["eff_kee"])
    {
        my["kee"] = my["eff_kee"];
        if (my["eff_kee"] < my["max_kee"])     { my["eff_kee"] ++; update_flag++; }
    } else update_flag++;

    if (my["max_force"] && my["force"] < my["max_force"] )
    {
        my["force"] += (int)me->query_skill("force", 1) / 2;
        if (my["force"] > my["max_force"]) my["force"] = my["max_force"];
        update_flag++;
    }

    if( my["food"] < 1 && userp(me) ) return update_flag;

    my["sen"] += my["con"] / 3 + my["mana"] / 10;
    if (my["sen"] >= my["eff_sen"])
    {
        my["sen"] = my["eff_sen"];
        if (my["eff_sen"] < my["max_sen"])     { my["eff_sen"] ++; update_flag++; }
    } else update_flag++;

    if (my["max_mana"] && my["mana"] < my["max_mana"])
    {
        my["mana"] += (int)me->query_skill("spells", 1) / 2;
        if( my["mana"] > my["max_mana"] ) my["mana"] = my["max_mana"];
        update_flag++;
    }

    return update_flag;
}



