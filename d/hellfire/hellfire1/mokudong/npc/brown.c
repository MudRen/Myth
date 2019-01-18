#include <ansi.h>
inherit NPC;

void create()
{

        set_name("��������", ({ "william" }) );
        set("race", "����");
        set("age", 3000);
        set("long", "һ�����ͺ���Ĺ��ս�������ܺ�ʵ����������ܲ\n");
        set("str", 20);
        set("cor", 30);
        set("con", 16);
        set("max_force", 3000);
        set("mana", 5000);
        set("force", 5000);
        set("max_mana", 3000);
        set("force_factor", 100);
        set("mana_factor", 150);
        set("max_kee", 2000);
        set("max_sen", 2000);
        set("verbs", ({ "bite", "claw"}) );
        set("title","���͵��ֹ���");
        set("combat_exp", 1000000+random(1000000));
         set("daoxing", 5000000);

    set_skill("dodge", 160);
    set_skill("unarmed", 100);
    set_skill("parry", 160);
    set_skill("moshenbu", 160);
    set_skill("force", 160);
    set_skill("wuxiangforce", 160);
    set_skill("sword", 200);
    set_skill("sanqing-jian", 200);
    set_skill("dao", 200);
    set_skill("spells", 200);
       map_skill("force", "wuxiangforce");
       map_skill("parry", "sanqing-jian");
       map_skill("sword", "sanqing-jian");
       map_skill("dodge", "moshenbu");
       map_skill("spells", "dao");
         set("chat_chance_combat", 30);
         set("chat_msg_combat", ({
        (: cast_spell, "light" :),
        (: cast_spell, "thunder" :),
        (: cast_spell, "dingshen" :)
       }));
        set_temp("apply/armor", 80);
        set_temp("apply/damage",80);
        set_temp("apply/armor_vs_force",300);
        set_weight(1000);
        setup();


        carry_object("/d/obj/armor/tongjia")->wear();
}


void init()
{
//        ::init();
        object who=this_player();
        if(!this_object()->query("taked"))
        add_action("do_take", "take");
       add_action("do_say", "okok");

        if(userp(who)){
        remove_call_out("greeting");
        call_out("greeting",1,who);
        }
}

void greeting(object who)
{
        object ob=this_object();

        tell_object(who,ob->name()+"˵�������ܴ��ҳ�ȥ���ұ�ץ�˺ܾ��ˡ�Please take me away!\n");
}

int do_take(string arg)
{
        object ob=this_object();
        object me=this_player();
        if(arg!="you back!" && arg!=(ob->query("id")+" back!"))
              {ob->command("say Please take me away!\n");
              return 1;}
          if(ob->query("taked")) {ob->command("say i'm waiting for somebody!"); return 1;}
         ob->set("taked",me->query("id"));
         ob->command("say ok!let's go!\n");
         return 1;

}

int do_say(string arg)
{
        object ob=this_object();
        object me=this_player();
        object mirror;
        message_vision(CYN+"$N˵����"+arg+"\n",me);
        if(me->query("id")!=ob->query("taked")) return 1;
        
        if(arg !="�����������ˡ�" && arg !="here" ) return 1;
        if(ob->query("giveok")) return 1;
        
        if( (environment(ob)->query("short")) != "ʮ�ֽ�ͷ") return 1; 
        message_vision(CYN+"$N��$n���Ե�˵����Thank a lot!you are my god!please take the magic mirror for my gift. \n",ob,me);
        message_vision(CYN+ob->query("id")+" give a magic mirror to "+me->query("id")+".\n",me);
        mirror=new("/d/obj/misc/xiaojie");
        mirror->set_name( HIC "ħ��" NOR,({"magic mirror",}));
        mirror->set("long","һ���ֹ����µ�ħ����");
        mirror->set("meidusha",1);
        mirror->set("no_drop",1);
         mirror->set("armor_prop/meidusha", 10); 
        mirror->move(me);
      call_out("destruct_ob",10,ob);
      ob->set("giveok",1);
        return 1;
}

void destruct_ob(object ob)
{
 destruct(ob);
}

