// by stey
// modify by mudring

inherit NPC;
#include <ansi.h>
#include "task1.h"
#include "task2.h"

void create()
{

    set_name("������", ({ "jiang ziya", "jiang", "ziya" }) );
    set("gender", "����" );
    set("long", "���������Ƿ�������������ֳ�һ��ͨ�쾵��\n");
    set("age",40);
    set("title", "��˵�е�����");
    set("str", 40);
    set("int", 30);
    set("con", 30);
    set("spi", 30);
    set("per", 30);
    set("class", "xian");
    set("attitude", "heroism");
    set("combat_exp", 1500000);
    set("daoxing", 2000000);
    set("max_kee", 20000);
    set("max_sen", 20000);
    set("force",5000);
    set("max_force",3000);
    set("force_factor", 150);
    set("mana", 5000);
    set("max_mana", 3000);
    set("mana_factor", 150);

    set("eff_dx", 600000);
    set("nkgain", 600);

    set_skill("unarmed",170);
    set_skill("dodge",400);
    set_skill("parry",170);
    set_skill("sword", 180);
    set_skill("force", 170);
    set_skill("spells", 170);
    set_skill("changquan", 170);
    set_skill("liangyi-sword", 180);
    set_skill("baguazhou", 170);
    set_skill("moshenbu", 170);
    set_skill("lengquan-force", 170);
    map_skill("unarmed", "changquan");
    map_skill("force", "lengquan-force");
    map_skill("spells", "baguazhou");
    map_skill("sword", "liangyi-sword");
    map_skill("parry", "liangyi-sword");
    map_skill("dodge", "moshenbu");

    set("chat_chance",1);
    set("chat_msg", ({
        name()+"˵���������������½��������ң���λ���ɿ�Ըȥ��Ȼ��ɣ�\n",
    }));

    setup();
    carry_object("/d/obj/armor/jinjia")->wear();
    carry_object("/d/sky/obj/zhanyaojian")->wield();
}

void init()
{
    add_action("do_task1", "dajiu");
    add_action("do_cancel1", "cancel");
/*
    add_action("do_task2", "baohu");
    add_action("do_cancel2", "over");
*/
}

