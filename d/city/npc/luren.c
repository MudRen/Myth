//Last Create  By PKYOU@DHXY 2002/05/25
inherit NPC;

void create()
{
	set_name("·��",({ "luren" }) );
        set("gender", "����" );
        set("age", 33);
	set("long", "����·��������һЩ���ͣ��������ʮ���ң�����Щ���ˡ�\n");
	set("str", 17);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
        set("combat_exp", 10000);
	set("attitude", "peaceful");

        setup();

       carry_object("/d/obj/cloth/linen")->wear();
	add_money("coin", 40);
}

