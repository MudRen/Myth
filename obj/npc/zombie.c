// zombie.c

#include <ansi.h>

inherit NPC;

void copy_status(object me, object ob);
void invocation(object me, object who);

void create()
{
	set_name("��ʬ", ({ "zombie" }) );
	set("long",
		"����һ�߱����÷�����ƵĽ�ʬ�������԰׵����Ͽ������κ�ϲŭ���֡�\n");
	set("max_kee", 500);
	set("max_sen", 500);
	set("max_mana", 200);
	set("mana", 200);
        set("max_force", 200); 
        set("force", 200);
	set("age", 50);
	set("str", 25);
	set("cor", 30);
	set("chat_chance", 15);
	set("chat_msg_combat", ({
		"��ʬ���з����ɺɵĽ�����\n",
		"��ʬ�����Ͽ�ʼ���Σ�һ��鴤�������Ƶش�С�\n",
		"��ʬ��ָ���ţ�ҧ���гݣ�¶��������Ц�ݡ�\n",
	}) );
	set_skill("unarmed", 30);
	set_skill("dodge", 30);

	set_temp("apply/damage", 15);

	setup();
}

void init()
{
	add_action("do_release", "release");
}

int do_release()
{
	object who=this_player();

	if( who != this_object()->query("possessed") )
		return notify_fail("ʲô��\n");

	message_vision("$N��$n���˻��֣�$n�������߿��ˡ�\n", who, this_object());
	destruct( this_object() );
	return 1;
}

int is_zombie() { return 1; }

void animate(object who)
{
	object me=this_object();
	set("possessed", who);
	copy_status(me, who);
	invocation(me, who);
	set_leader(who);
}
void copy_status(object me, object ob)
{
        mapping skill_status,map_status;
        string *sname,*mname;
        int i;

        skill_status=me->query_skills();
        sname=keys(skill_status);
        for(i=0;i<sizeof(skill_status);i++) {
                me->delete_skill(sname[i]);
        }
        skill_status=ob->query_skills();
        sname=keys(skill_status);
        for(i=0;i<sizeof(skill_status);i++) {
                me->set_skill(sname[i],skill_status[sname[i]]);
        }
        if ( mapp(map_status = me->query_skill_map()) ) {
                mname  = keys(map_status);

                for(i=0; i<sizeof(map_status); i++) {
                        me->map_skill(mname[i]);
                }
        }

        map_status = ob->query_skill_map();
        mname  = keys(map_status);

        for(i=0; i<sizeof(map_status); i++) {
                me->map_skill(mname[i], map_status[mname[i]]);
        }
        me->set("str",ob->query("str"));
        me->set("int",ob->query("int"));
        me->set("con",ob->query("con"));
        me->set("per",ob->query("per"));
        me->set("cor",ob->query("cor"));
        me->set("spi",ob->query("spi"));
        me->set("cps",ob->query("cps"));
        me->set("kar",ob->query("kar"));

        me->set("max_kee",ob->query("max_kee"));
        me->set("eff_kee",ob->query("eff_kee"));
        me->set("kee",ob->query("kee"));

        me->set("max_gin",ob->query("max_gin"));
        me->set("eff_gin",ob->query("eff_gin"));
        me->set("gin",ob->query("gin"));

        me->set("max_sen",ob->query("max_sen"));
        me->set("eff_sen",ob->query("eff_sen"));
        me->set("sen",ob->query("sen"));

        me->set("max_force",ob->query("max_force"));
        me->set("force",ob->query("force"));
        me->set("force_factor",ob->query("force_factor"));

        me->set("max_mana",ob->query("max_mana"));
        me->set("mana",ob->query("mana"));
        me->set("mana_factor",ob->query("mana_factor"));

        me->set("combat_exp",ob->query("combat_exp"));
        me->set("daoxing",ob->query("daoxing"));
}

void invocation(object me, object who)
{
        int i;
        object *enemy;

	message_vision(HIY"\n$N����ս����\n\n"NOR, me);

        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
        set_leader(who);
}


void die()
{
	object corpse;
        if( environment() ) {
                message("sound", "��ʬ�����ص�����ȥ����Ϊһ̲Ѫˮ��\n", environment());
        }

	destruct(this_object());
}

int heal_up()
{
	object master;

	if( objectp(master = query("possessed")) 
	&&	(int)master->query("mana") > 100 
	&&	(int)master->query("kee") > 100) {
		message("tell",
HIR"��������ڵ�������" + name()+"һ��һ�����ȥ�ˡ�\n"NOR, master);
		master->add("mana", -20);
		::heal_up();
		return 1;		// Always acquire power from master.
	} else {
		call_out("die", 1);
		return ::heal_up();
	} 
}


