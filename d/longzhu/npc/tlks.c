// ������˹ by Calvin

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string suanming(object me);
void create()
{
        set_name(HIW"������˹"NOR, ({"telan kesi", "tlks", "telan", "kesi"}));
        set("title", HIG"���鴫��"NOR);
        set("gender", "����" );
        set("age", 10);
        set("per", 30);
        set("str", 60);
set("long","�����˱������������˲���Ķ��ӡ�\n");

        set("class", "yaomo");
        set("combat_exp", 120000000);
        set("daoxing", 100000000);

//        set("rank_info/respect", "����");
        set("attitude", "peaceful");
        set_skill("unarmed", 1000);
        set_skill("cuixin-zhang", 1000);
        set_skill("dodge", 1000);
        set_skill("xiaoyaoyou", 1000);
        set_skill("parry", 1000);
        set_skill("sword", 1000);
        set_skill("bainiao-jian", 1000);
        set_skill("blade", 1000);
        set_skill("bingpo-blade", 1000);
        set_skill("throwing", 1000);
        set_skill("force", 1000);   
        set_skill("ningxie-force", 1000);
        set_skill("literate", 1000);
        set_skill("spells", 1000);
        set_skill("dengxian-dafa", 300);

        map_skill("spells", "dengxian-dafa");
        map_skill("force", "ningxie-force");
        map_skill("unarmed", "cuixin-zhang");
        map_skill("sword", "bainiao-jian");
        map_skill("blade", "bingpo-blade");
        map_skill("dodge", "xiaoyaoyou");

        set("max_sen", 20000);
        set("max_kee", 20000);
        set("force", 10000);
        set("max_force", 6000);
        set("mana", 6000);
        set("max_mana", 6000);  
        set("force_factor", 1000);
        set("mana_factor", 1000);

        set_temp("apply/damage", 50);
        set_temp("spply/armor", 50);
        set_temp("apply/dodge", 50);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "juanbi":),
                (: cast_spell, "bingfeng" :),
                (: cast_spell, "tuntian" :),
                (: perform_action, "sword", "chaofeng":),
            (: perform_action, "sword", "feijian":),
       }) );

            setup();
        carry_object("/d/quest/longzhu/armor/muji")->wear();
        carry_object("/d/quest/longzhu/weapon/duanjian")->wield();
}

void die()
{
 int i;
 object me,*inv;
 if(objectp(me=query_temp("last_damage_from") ))
        {
            inv = all_inventory(this_object());
            for(i=0; i<sizeof(inv); i++)
            {
           if (inv[i]->query("id")=="4" || inv[i]->query("id")=="lan longzhu") 
                {
                   inv[i]->move(me);

                   message_vision("$N����һö����ɫ�����ӣ�$n��æһ��ץ�����\n",this_object(),me);
            message("channel:rumor",HIG+"��"HIW"���鴫˵"HIG"��"HIC"�����"HIW"��"+me->query("name")+"�ڳ������������õ���"HIB"������"HIW"��\n"+NOR,users());
         }
        }
  }
 ::die();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 10);
        set("inquiry", ([
           "name" : "���ǲ���Ķ���,��ô? ���۸�����?��\n",
            "here" : "����������������������㡣\n", 
            "����" : "��˵�е�����һ�����߿�,����ֻ��һ����ɫ������,�������Ҫ�Ļ�,��ȥ�ҿ�������������ҽ�����\n", 
         ]) );

        set("chat_msg", ({
            "������˹˵������ô����û�������氡?\n",       
                "������˹�������´������㼸�ۡ�\n",
                "������˹���˿���,���Ӽ�Ϊ��ŭ��\n",
                "������˹���˿����ʵ�:������֪��������?\n",
                (: random_move :)
        }) );
}


int accept_object(object me, object ob)
{
object zhu;
zhu=new("/d/quest/longzhu/obj/4.c");
if((string)ob->query("id")=="fen longzhu" )
{
message_vision(HIR"������Ե,�ҾͰ���������ı�����$N��Ϊ�������!\n"+HIC"˵��������˼�ó�һ�����������$N!\n\n",me);
zhu->move(me);
return 1;
}
else
{
command("say ���ҵ����ҵ���������̫�����ˡ�");
 return 1;
}
}

