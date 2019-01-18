//npc--taxue

inherit NPC;

#include <ansi.h>

void create()
{
        set_name(HIW"̤ѩ"NOR, ({"ta xue", "xue"}));
        set("age", 22);
        set("attitude", "peaceful");
        set("gender", "Ů��");
        set("title", HIC"��������"NOR);
        set("str", 30);
        set("int", 20);
        set("per", 40);
        set("con", 20);
        set("max_gin", 5000);
        set("max_kee",5000);
        set("max_sen", 5000);
        set("combat_exp", 10000000);
        set("daoxing", 10000000);


        set("force", 14000);
        set("max_force", 14000);
        set("force_factor", 500);
        set("mana",14000);
        set("max_mana", 14000);
        set("mana_factor", 400);
        set_skill("unarmed", 250);
        set_skill("force", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("spells", 250);
        set_skill("whip", 250);
        set_skill("jueqingbian",250);
        set_skill("moonforce",250);
        set_skill("moonshentong",250);
        set_skill("moondance",250);
        set_skill("baihua-zhang",250);
        map_skill("dodge","moondance");
        map_skill("unarmed","baihua-zhang");
        map_skill("force","moonforce");
        map_skill("spells","moonshentong");
        map_skill("axe","jueqingbian");


        create_family("�¹�", 2, "����");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "mihun" :),
                (: cast_spell, "arrow" :)  
  }) );

        setup();

        add_money("gold", 2);

        carry_object("/d/obj/cloth/luoyi")->wear();
        carry_object("/d/obj/weapon/whip/jueqingwhip")->wield();

}

        void kill_ob (object ob)
{
        set_temp("no_return",1);
        set_temp("my_killer",ob);
        ::kill_ob(ob);
}

        void die()
{       
        object ob = query_temp("my_killer");
        object deng;

    if (objectp(ob) &&!(deng = present("baolian deng",ob)) && (ob->query("bld/mother") == 1))
{
        message_vision("��������һ�����������ɡ�\n"NOR,this_object());
        message_vision(HIW"̤ѩ"NOR+"����$Nһ�������� \n",ob);
        message_vision("�һ��Ʋ�������ȥ���ܳͷ���\n\n",this_object());
        deng = new("/d/quest/bld/obj/deng");
        deng->move(ob);
        ob->set("bld/taxue",1);
}
                
        message_vision(HIW"̤ѩ"NOR+"��������һ��̾�˿�����
\n\n",this_object());
        message_vision(HIW"̤ѩ"NOR+"����һ�����̶�ȥ�� \n\n",this_object());
        destruct(this_object());
}


