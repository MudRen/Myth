
/* <SecCrypt CPL V3R05> */
 
// lzl.c
//lizuole 99.11.12

#include <ansi.h>
#include <login.h>
inherit NPC;

void create()
{
        set_name(HIR"������"NOR, ({"lizuole","lzl","le"}));
        set("title",HIC"�����ϰ�"NOR);
        set("gender", "����" );
        set("age", 23);
        set("class","taoist");
        set("long", "����Ǳ�����е��ܲã�������Ϊ��Ŀ���д������С�\n");
        set("combat_exp", 8000000);
        set("attitude", "peaceful");
       set("max_kee", 5000);
       set("max_gin", 1000);
       set("max_sen", 5000);
       set("force", 5000);
       set("max_force", 4500);
       set("force_factor", 150);
       set("max_mana", 4500);
       set("mana", 5000);
       set("mana_factor", 150);
       set("combat_exp", 3000000);
       set_skill("literate", 150);
       set_skill("unarmed", 150);
       set_skill("dodge", 170);
       set_skill("parry", 170);
       set_skill("stick", 150);
       set_skill("spells", 200);
       set_skill("dao", 180);
       set_skill("puti-zhi", 150);
       set_skill("wuxiangforce", 180);
       set_skill("force", 200);
       set_skill("qianjun-bang", 180);
       set_skill("jindouyun", 180);
       map_skill("spells", "dao");
       map_skill("unarmed", "puti-zhi");
       map_skill("force", "wuxiangforce");
       map_skill("stick", "qianjun-bang");
       map_skill("parry", "qianjun-bang");
       map_skill("dodge", "jindouyun");
       set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: cast_spell, "light" :),
                (: cast_spell, "dingshen" :),
                (: cast_spell, "thunder" :),
                (: cast_spell, "fenshen" :),
                (: cast_spell, "pili" :),
                (: cast_spell, "qiankun" :),
                (: cast_spell, "invocation" :),
        }) );
        setup();
        carry_object("/d/lizuole/obj/choupao")->wear();
        carry_object("/d/lizuole/obj/huanlebang")->wield();
       // carry_object("/d/obj/book/chunyang")->tear();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 3);
        set("inquiry", ([
                "name" : "����Ǳ�����е��ܲã�Ҳ�����������ˡ�\n",
                "here" : "��û������������ط��������µ�һ�������ڡ�\n", 
   ]) );

   /*     set("chat_msg", ({
       "�����ָ���˵���������������Ǳ��ѽ��\n",   
                "�������������´������㼸�ۡ�\n",
                "���������۽�Ƴ����һ��˵��ûǮ��һ������ȥ��\n",
       }) );*/
}

int heal_up()
{

        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        object stone;

        this_object()->add("time", 1);
        if( (int)this_object()->query("time") >= 3 ) {
        message("vision",name() + "���˿���ĭ���ݺ�˵�����´α����������
���������˳�ȥ��\n", environment(),this_object() );
        destruct(this_object());

        }
        return;
}

