//Cracked by Roath
#include <ansi.h>
#include <login.h>

inherit NPC;
void ask_life();

string *death_msg = ({  
        HIW "���й����������֣�˵���������ģ���Ī���ܣ��������������Һ����㻹����\n\n" NOR,
        HIW "���йٿ�����Ц��Ц��˵����������������Ҳ��Ҫ̫�ѹ��ˡ�\n\n" NOR,
        HIW "���йٴӻ����ó�һ���ڵװ��ֵĲ��ӷ����š�����\n\n" NOR,
        HIW "���йٺ��ϲ��ӣ�˵���������������������棬��������㻹��ȥ�ɣ�\n\n" NOR,
        HIW "���й���������һָ����Ļ����ֻص����Լ����ϡ�����\n\n"
                "һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣\n\n" NOR,
});

void create()
{
       set_name(HIW"����"NOR, ({"cui jue", "cui"}));
	set("title",HIW"����й�"NOR);
       set("gender", "����");
	set("long", "���й�ԭ������Ϊ�٣��������£����󱻷�Ϊ�����й١�\n");
       set("age", 30);
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 30);
       set("max_kee", 600);
       set("max_gin", 600);
       set("max_sen", 600);
       set("force", 650);
       set("max_force", 600);
       set("force_factor", 20);
       set("max_mana", 600);
	set("mana",600);
       set("mana_factor", 10);
       set("combat_exp", 100000);
  set("daoxing", 100000);

       set_skill("unarmed", 50);
       set_skill("dodge", 40);
       set_skill("parry", 70);
	set_skill("sword", 80);
        set_skill("force", 50);

setup();

        carry_object("/d/obj/cloth/choupao")->wear();
        carry_object("/d/obj/weapon/sword/panguanbi")->wield();
}

void init()
{
        ::init();
        if( !previous_object()
        ||      !userp(previous_object()) )
                return;

        call_out( "death_stage", 5, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
        //if( !ob || !present(ob)) return;
        if(!ob) return;
	if( !ob->is_ghost() ) return;

	if(!present(ob)) {
	    message_vision("ڤڤ֮�й���һ�����磬��$N�Ĺ���ס�����ˡ�\n",
		    ob);
	    ob->move(environment(this_object()),2);
	    ob->start_busy(3);
	}
        tell_object(ob, death_msg[stage]);
        if( ++stage < sizeof(death_msg) ) {
                call_out( "death_stage", 5, ob, stage );
                return;
        } else
                ob->reincarnate();
	ob->set("gin", (int)ob->query("max_gin"));
	ob->set("kee", (int)ob->query("max_kee")/4);
	ob->set("sen", (int)ob->query("max_sen")/4);
        ob->move(REVIVE_ROOM);
        tell_room(environment(ob), 
		"��ǰһ������Ʈ���������ؾ۳���һ���˵����ӡ�\n",({ob, ob}));
}
