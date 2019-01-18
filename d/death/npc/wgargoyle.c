// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;
//  8  inherit F_CLEAN_UP; delete by mudring@sjsh......

string *death_msg = ({
        HIW "���޳�˵����ι�������ģ����ʲô���֣�\n\n" NOR,
        HIW "���޳���������۹ⶢ���㣬����Ҫ�������һ���Ƶġ�\n\n" NOR,
        HIW "���޳����ߡ���һ�����������ͳ�һ�����ʲ�Ķ��������š�\n\n" NOR,
        HIW "���޳����ϲ��ӣ�˵�����ף�����δ������ô���ܣ�\n\n" NOR,
        HIW "���޳�ɦ��ɦͷ��̾�������˰��ˣ����߰ɡ�\n\n"
                "һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣\n\n" NOR,
});

void create()
{
        set_name("���޳�", ({ "white gargoyle", "gargoyle" }));
        set("long",
"���޳����ų�������ͷ�����㣬���׵����Ͽ������κ�ϲŭ���֡�\n");
        set("attitude", "peaceful");
set("chat_chance", 15);
set("chat_msg", ({
"���޳�����һ����������������������������ע��������ʱ�򣬵�����һ�ۡ�\n",

"���޳��ѳ�������ͷ��������������������Լ��ְ��ֳ�����ָ��\n"
        }) );
	set("per", 100);
	set("str", 20);
	set("int", 20);
        set("age", 217);
	set("title", "ӭ��ʹ��");
        set("combat_exp", 100000);
  set("daoxing", 100000);

        set("max_gin", 600);
        set("max_kee", 700);
        set("max_sen", 600);
	set("class", "youling");
	set("force", 400);
	set("max_force", 400);
	set("force_factor", 20);
	set("max_mana", 300);
	set("mana", 300);
	set("mana_factor", 15);
	set_skill("ghost-steps", 50);
        set_skill("dodge", 50);
        set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("spells", 50);
	set_skill("gouhunshu", 50);
	set_skill("jinghun-zhang", 50);
	set_skill("force", 50);
	set_skill("tonsillit", 50);
	map_skill("spells", "gouhunshu");
	map_skill("dodge", "ghost-steps");
	map_skill("force", "tonsillit");
	map_skill("unarmed", "jinghun-zhang");
create_family("���޵ظ�", 3, "���");

        setup();
	carry_object("/d/obj/cloth/bai")->wear();
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
        if( !ob || !present(ob) ) return;
        if( !ob->is_ghost()) {
                if( visible(ob)&&(string)ob->query("family/family_name")!="���޵ظ�" ){
                        command("say ι��������������ʲô��");
			command("kick " + ob->query("id"));
                        return;
                }
                return;
        }

        tell_object(ob, death_msg[stage]);
        if( ++stage < sizeof(death_msg) ) {
                call_out( "death_stage", 5, ob, stage );
                return;
        } else
                ob->reincarnate();
		ob->set("gin", (int)ob->query("max_gin"));
        ob->move(REVIVE_ROOM);
        message("vision",
                "���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"
                "�ܾ��ˣ�ֻ����һֱû������\n", environment(ob), ob);
}


void attempt_apprentice()
{	object me;
	me = this_player();
      command("grin");
	if(me->is_ghost() ){
	me->reincarnate();
	me->set("gin", (int)me->query("max_gin"));
	}
        command("say �ܺã�" + RANK_D->query_respect(me) +
"���Ŭ�������ձض��гɡ�\n");
       command("recruit " + me->query("id") );
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youling");
}

�
