// С�� by Calvin 

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("С��", ({"xiao lin","xiao","lin"}));
        set("title", HIG"��Ҷͯ��"NOR);
        set("gender", "����" );
        set("color", HIW );
        set("age", 16);
        set("per", 33);
        set("str", 60);
          set("taskguai",1);
set("long","һλ��������͵�С���ӡ�\n");

        set("attitude", "aggressive");
       set("class", "sanjie");
       set("shen_type", 1);
       set("max_kee", 100000);
       set("max_gin", 100000);
       set("max_sen", 100000);
             set("family/family_name", "����ɽ");
       set("force", 6000);
       set("max_force", 6000);
       set("force_factor", 300);
       set("max_mana", 6000);
       set("mana", 6000);
       set("mana_factor", 1000);
       set("combat_exp", 100000000);
       set("daoxing", 100000000);

        set_skill("dodge", 2000);
        set_skill("parry", 1000);
        set_skill("spells", 1000);  
        set_skill("tianmogong", 1000);
        set_skill("literate", 1000);
        set_skill("blade", 1000);  
        set_skill("zileidao", 1000);
        set_skill("zhaoyangbu", 1000);
        set_skill("force", 1000);   
        set_skill("huntianforce", 1000);

        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("blade", "zileidao");
        map_skill("parry", "zileidao");
        map_skill("dodge", "zhaoyangbu");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: perform_action, "blade", "leihuo" :),
        (: perform_action, "blade", "huanying" :),
        }) );

        setup();
        carry_object("/d/quest/longzhu/armor/xinjia")->wear();
        carry_object("/d/quest/longzhu/weapon/xindao")->wield();
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
              if (inv[i]->query("id")=="6" || inv[i]->query("id")=="liang longzhu")
                {
                   inv[i]->move(me);

                   message_vision("$N����$n˵��:��������,��Ӧ�õõ�������顣\n",this_object(),me);
            message("channel:rumor",HIG+"��"HIW"���鴫˵"HIG"��"HIC"�����"HIW"����˵"+me->query("name")+"�����ָ����õ���"HIC"������"HIW"��\n"+NOR,users());
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
           "name" : "������Ҷͯ�� С�� ��\n",
            "here" : "������Ҷ���¡�\n", 
            "����" : "��˵�е�����ֲ����߸���ͬ�ĵط���\n", 
         ]) );

        set("chat_msg", ({
            "С��˵��������ֱ�����������,�ռ����˿ɲ����װ�!\n",       
                "С���������Ŀ������һ��һ����\n",
                "С��˵��:�����õط����������Ѳ���ʲô�����ġ�\n",
                "���˿����ʵ�:������֪��������?\n",
        }) );
}


