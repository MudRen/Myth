//Cracked by Roath

#include <ansi.h>
inherit NPC;

void create()
{
          set_name("����", ({"ao guang", "ao","guang","longwang","wang"}));

   set("long","�����Ƕ��������������ֱֵܷ��ƹܶ��������ϣ����ĺ���
������ˮ���ڶ࣬���ƺƴ�ٲȻ����һ����\n");
          set("gender", "����");
          set("age", 66);
   set("title", "��������");
   set("class","dragon");
          set("attitude", "aggressive");
          set("shen_type", 1);
        set("combat_exp", 1260000);
        set("rank_info/respect", "����");
          set("per", 20);
          set("str", 30);
          set("max_kee", 3000);
          set("max_gin", 400);
          set("max_sen", 800);
          set("force", 3000);
          set("max_force", 1500);
          set("force_factor", 120);
          set("max_mana", 800);
          set("mana", 1600);
          set("mana_factor", 40);
          set("combat_exp", 1200000);
          set_skill("unarmed", 200);
          set_skill("dodge", 180);
          set_skill("force", 180);
          set_skill("parry", 180);
          set_skill("hammer", 190);
          set_skill("fork", 180);
          set_skill("spells", 150);
          set_skill("seashentong", 150);
          set_skill("dragonfight", 200);
          set_skill("dragonforce", 190);
          set_skill("huntian-hammer", 190);
          set_skill("fengbo-cha", 200);
          set_skill("dragonstep", 180);
          set_skill("longshen-yinggong",200);   
          set_skill("jinlin-jia",180);
          map_skill("jinlin-jia","longshen-yinggong");
          map_skill("spells", "seashentong");
          map_skill("unarmed", "dragonfight");
          map_skill("force", "dragonforce");
          map_skill("fork", "fengbo-cha");
          map_skill("parry", "fengbo-cha");
          map_skill("dodge", "dragonstep");

          create_family("��������", 1, "ˮ��");
          set_temp("apply/armor",50);
          set_temp("apply/damage",25);
          setup();

        carry_object("/d/sea/obj/longpao")->wear();
}


void init()
{
     object ob = this_player();
     string env;
     env=environment()->query("short");
     if( env == "[1;33m����̨[m"&& ob->query("fish") ) 
     message("channel:chat",HIC+"�����㡿�������̵�"+ ob->query("name") +"������˭�ٸҵ��㣬������Ӳ�������\n"+NOR,users());

}
