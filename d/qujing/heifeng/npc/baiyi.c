//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/npc/baiyi.c
 
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("������ʿ", ({"baiyi xiushi","xiu shi"}));
        set("long", "һλ��ĺ����������ӡ�\n");

        set("gender", "����");
        set("attitude", "peaceful");

        set("age", 80);
        set("combat_exp", 50000);
        set("daoxing",30000);
        set("shen_type", 1);
        set("per", 10);
        set("max_kee", 380);
        set("max_gin", 300);
        set("force", 250);
        set("force_factor", 5);
        set_skill("force", 20+random(20));
        set_skill("unarmed", 20+random(20));
        set_skill("dodge", 20+random(20));
        set_skill("parry", 20+random(40));

        setup();
        carry_object("/d/obj/cloth/sengyi")->wear();

        setup();
}
void kill_ob(object ob)
{
        
    object where=environment(ob);
    object bear = present("hei xiong",where);
    object lingxu=present("lingxu zi",where);

        if ( bear )
        bear->kill_ob(ob);
        if ( lingxu )
        lingxu->kill_ob(ob);
        ::kill_ob(ob);
        return;
}        


void die()
{

        message_vision(HIY"������ʿ���˸������ˡ�\n",this_object());
        message_vision("ֻ��һ���׻������ڵ��ϡ�\n"NOR,this_object());
        this_object()->set_name("�׻���",({"baihua she","snake"}));
        ::die();
}
    
