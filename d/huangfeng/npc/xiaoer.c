// created by angell 1/1/2001
// room: /d/qujing/huangfeng/npc/xiaoer.c

inherit F_VENDOR_SALE;

void create()
{
    reload("wang_xiaoer");
       set_name("��С��", ({"wang xiaoer", "wang","xiaoer","er","waiter" }));
       set("long", "С�Ƶ�Ļ�ƣ�һ������������ģ����\n");
       set("gender", "����");
	set("title", "���");
	set("combat_exp", 3000);
       set("age", 46);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
        set("vendor_goods", ([
                "jiudai": "/d/ourhome/obj/hdjiudai",
                "gourou": "/d/ourhome/obj/gourou",
                "yumi": "/d/qujing/huangfeng/obj/yumi",
		    "mifan": "/d/qujing/huangfeng/obj/mifan",
        ]) );

	setup();
       add_money("silver", 2);
	add_money("coin", random(80));
        carry_object("/obj/cloth")->wear();

}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say( name()+"Ц�����˵������λ" +
RANK_D->query_respect(ob)
                                + "�����������Ѱɡ�\n");
                        break;
	}
}
