// head.c ���ϴ�

inherit NPC;

void create()
{
       set_name("����չ", ({"xia pengzhan", "xia"}));
       set("title", "���կǿ��ͷ��");
       
set("long","����չԭ�ǳ�������һ����ͷ���������Ѹģ��������ǿ����
ʹһ·��赶�����������Ƶ������ޱȣ�\n");
       set("gender", "����");
       set("age", 37);
	set("str", 25);
       set("attitude", "aggressive");
       set_skill("blade",60);
        set_skill("parry", 60);
	set_skill("dodge", 60);
	set_skill("unarmed", 60);
	set_skill("yange-blade", 40);
	set_skill("yanxing-steps", 40);
	map_skill("dodge", "yanxing-steps");
	map_skill("blade", "yange-blade");
	map_skill("parry", "yange_blade");
       set("max_kee", 700);
	set("bellicosity", 5000);
       set("max_sen", 600);
       set("force", 350);
       set("max_force", 300);
       set("force_factor", 20);
       set("combat_exp", 60000);
setup();
carry_object("/d/obj/weapon/blade/yanblade")->wield();
carry_object("/d/obj/armor/yinjia")->wear();
carry_object("/d/obj/book/parry_book");
carry_object("/obj/dust");
add_money("silver", 50);
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "����չ�ȵ�����������" + RANK_D->query_rude(ob) +
"���ҿ��㲻����ˣ�\n");
}
