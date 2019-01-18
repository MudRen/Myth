#include <ansi.h>
int wind();

inherit NPC;
void create()
{
  set_name("����", ({"feng shen", "fengshen", "shen"}));
  set("gender", "����");
  set("attitude", "friendly");
  set("combat_exp", 20000000);
  set("daoxing", 30000000);

  set("age", 100);
  set("per", 100);
  set("str", 30);
  set("int", 30);
  set("cor", 30);
  set("cps", 30);
  set("con", 30);
  set("max_kee", 10000);
  set("max_sen", 10000);
  set("force", 10000);
  set("max_force", 5000);
  set("max_mana", 7000);
  set("mana",8000);  
  set("mana_factor",500);  
  set("force_factor",200);  
  set_skill("spells", 250);
  set_skill("force", 250);
  set_skill("unarmed", 250);
  set_skill("puti-zhi", 250);
  set_skill("parry", 250);
  set_skill("wuxiangforce", 250);
  set_skill("dao", 250);
  set_skill("dodge", 2000);
  set_skill("jindouyun", 250);
  map_skill("dodge", "jindouyun");
  map_skill("unarmed", "puti-zhi");
  map_skill("spells", "dao");
  map_skill("force", "wuxiangforce");

         set("chat_chance_combat", 50);
         set("chat_msg_combat", ({
        (: wind :)
       }));
        set_temp("apply/armor", 300);

  setup();
}
int wind()
{
remove_call_out("hurting");
message_vision( HIC "\n\n$N��һ�һ���紵�𣡣�\n\n" NOR,
this_object());
call_out("hurting",random(10)+2);

        return 1;
}

int hurting()
{
        int i;
        int dam;
        object *inv;
        message_vision( HIC "\n\n��紵��������ض��챻���ѣ�����\n\n",this_object());
        inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
        if( living(inv[i]))
        if( inv[i] != this_object())
        {
        dam = random(500)+200 ;
        inv[i]->receive_damage("kee",dam);
        inv[i]->receive_wound("kee",dam/2);
        COMBAT_D->report_status(inv[i]);
        }
        return 1;
}

void die()
{
    object rope;
    string rp="/d/zhuxian/obj/xianxian.c";

	rope = new(rp);
    if( environment() ) {
    message("vision", "һ����ι���������ʧ����Ӱ���٣���ͻȻ���ֵ��϶���һ��������\n", environment());
    }
    rope->move(environment(this_object()));
    destruct(this_object());
}
�
