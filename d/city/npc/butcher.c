//NPC /d/city/npc/butcher.c
//Created by waiwai@2001/05/03

#include <allobj.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("֣����", ({ "butcher", "zheng" }) );
        set("title", "��������");
        set("gender", "����" );
        set("age", 35);
        set("long", "�㿴��һ���⺷�Ĵ��ͷ, �����øֵ���ţ�ǡ�\n");
        set("str", 29);
        set("int", 14);
        set("per", 18);
        set("combat_exp", 90000);
        set("attitude", "heroism");
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("dagger", 200);

        set("vendor_goods", ([
	         "1": CITY_NPC"meat/b_beef",
	         "2": CITY_NPC"meat/hind",
	         "3": CITY_NPC"meat/tail",
	         "4": CITY_NPC"meat/zasui",
	         "5": CITY_NPC"meat/dog_m",
        ]) );

       set("changed", "����");
	set("area_name","������");

        setup();
        carry_object("/obj/cloth")->wear();
        carry_object(CITY_NPC"obj/knife")->wield();
        carry_object(CITY_NPC"obj/skin_belt")->wear();
}

void init()
{
        object area,ob;
        area=new("/obj/area");
        area->create(query("area_name"));
        set("banghui",(string)area->query("banghui"));
        destruct(area);

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
       if( ob->query("env/invisibility") ) return;

        switch( random(4) ) {
                case 0:
                        say( "������޹�ͷ������ţ����Ǻõ����޵ú����! \n");
                        break;
                case 1:
                        say( "����ҡҡͷ, ̾�˿���˵����, ��֪�Ǳ��񵶾���"
                                +"�����⵶��������...\n");
                        break;
                case 2:
                        say( "�����ֿ�����, Ц�ŵ�����λ"  
                                + RANK_D->query_respect(ob)
                                + "��Ҫ��������? \n");
                        break;
                case 3:
                        say( "����æ�Ÿ���ȡ��, �ƺ�ûע�⵽�������\n");
                        break;
        }
}

 
