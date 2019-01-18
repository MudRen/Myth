// created by angell 1/1/2001
// room: /d/qujing/huangfeng/npc/wangshan.c

inherit F_VENDOR_SALE;

void create()
{
        reload("huangfeng_wangshan_huangfeng");
         set_name("����", ({"wang an", "wang","lao ban"}));
        set("title", "���ϰ�");
        set("gender", "����");
        set("age", 25);
        set("long", "һ����׳�ĺ��ӣ���ü��Ŀ
����Ŀ���䵽������ϣ��㷢�������о���������������ֱ�ӣ�\n");

        set("combat_exp", 70000);
	set_skill("kaishan-chui", 30);
        set_skill("hammer", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
	set_skill("jindouyun", 50);
	map_skill("dodge", "jindouyun");
	map_skill("hammer", "kaishan-chui");
	map_skill("parry", "kaishan-chui");
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 5);

        set("vendor_goods", ([
                "shield": "/d/obj/armor/niupi",
                "sword": "/d/obj/weapon/sword/changjian",
                "blade": "/d/obj/weapon/blade/blade",
                "spear": "/d/obj/weapon/spear/tieqiang",
                "staff": "/d/obj/weapon/staff/chanzhang",
                "hammer": "/d/obj/weapon/hammer/tongchui",
        ]) );

        setup();
        carry_object("/d/obj/cloth/hei")->wear();
        carry_object("/d/obj/weapon/hammer/tongchui")->wield();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
		call_out("greeting",1, ob);
        }
        add_action("do_vendor_list", "list");
}

int accept_fight(object me)
{
        command("say �ðɣ��ͱȻ������ӣ������ܶൢ�����кö��û���أ�\n");
        return 1;
}

