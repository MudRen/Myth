#include <ansi.h>
inherit NPC;
void create()
{
        object ob;

        set_name("ħ����", ({ "tian wang", "zengzhang tianwang", "qing", "tianwang" }) );
        set("gender", "����" );
        set("long",
                "��������Ϊ�Ĵ�����֮��, ��߶����ĳ�, ����һ�˳�ǹ, \n"
                "ǹ���Ƿ��켫, �����ܴ������Ʊ�����, ���أ�ˮ���𣬷硹\n"
                "��ʽһ��, ���޽���Ҳ���ӡ�\n"
        );
        set("age",50);
        set("title", "��������");
        set("attitude", "heroism");
        set("str",40);
        set("int",30);
        set("max_kee",5100);
        set("kee",6100);

        set("max_sen",5100);
        set("sen",5100);
        set("combat_exp",4000000);
        set("daoxing",4500000);
        set("force",5000);
        set("max_force",2500);
        set("mana",5000);
        set("max_mana",3000);
        set("force_factor", 250);
        set("mana_factor",250);
        

        set("eff_dx", 3500000);
        set("nkgain", 800);


        set_skill("unarmed",180);
        set_skill("yingzhaogong", 180);
        set_skill("parry",180);
        set_skill("dodge",400);
        set_skill("sword",300);
        set_skill("ningxie-force",300);
        set_skill("bainiao-jian",250);
        set_skill("force",300);
        set_skill("spells", 300);
        set_skill("moshenbu", 350);
        map_skill("dodge", "moshenbu");
        map_skill("force", "ningxie-force");
        map_skill("parry", "bainiao-jian");
        map_skill("sword","bainiao-jian");
        map_skill("unarmed", "yingzhaogong");

        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "sword", "bxff" :),
                (: perform_action, "sword", "zheng" :),
                (: perform_action, "sword", "chaofeng" :),
        }) );

        setup();

        ob=carry_object("/d/obj/weapon/sword/qingfeng");
        ob->wield();
        ob->set_name("���Ʊ���", ({ "sword", "bao jian" }) );

        carry_object("/d/obj/armor/jinjia")->wear();
}




void die ()
{
  object me = this_object();
  message_vision (HIY"$N�ŵ����Ⱦ��ܡ�\n"NOR,me);
  destruct (this_object());
  return ;
}
