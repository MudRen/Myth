//Cracked by Roath
 
inherit NPC;
#include <ansi.h>
void create()
{
   set_name("ľ������", ({ "mucha xingzhe", "mucha", "xingzhe" }));
   set("long","������������ͽ�ܡ�");
   set("gender", "����");
   set("age", 35);
   set("attitude", "peaceful");
   set("max_kee", 5000);
   set("max_gin", 5000);
   set("max_sen", 5000);
   set("force", 4000);
   set("max_force", 2000);
   set("force_factor", 145);
   set("max_mana", 3000);
   set("mana", 6000);
   set("mana_factor", 150);
   set("combat_exp", 20000000);
   set("daoxing",150000000);
   set_skill("literate", 150);
   set_skill("spells", 200);
   set_skill("buddhism", 200);
   set_skill("unarmed", 150);
   set_skill("jienan-zhi", 150);
   set_skill("dodge", 180);
   set_skill("lotusmove", 160);
   set_skill("parry", 150);
   set_skill("force", 180);
   set_skill("lotusforce", 180);
   set_skill("staff", 150);
   set_skill("lunhui-zhang", 180);
   set_skill("spear", 150);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("force", "lotusforce");
   map_skill("parry", "lunhui-zhang");
   map_skill("staff", "lunhui-zhang");

   setup();
   carry_object("/d/nanhai/obj/jiasha")->wear();
   carry_object("/d/nanhai/obj/jingu1");
   carry_object("/d/nanhai/obj/nine-ring")->wield();
}

void init()
{
  object ob = this_object();
  object me = this_player();
  int i;
  if( ! me->query_temp("sha_killed") 
    ||! me->query("obstacle/huangfeng")
    || me->query("combat_exp") < 10000
    || me->query("obstacle/liusha") == "done")
    return;
  i = random(500);
  me->add("obstacle/number",1);
  me->set("obstacle/liusha","done");
      me->add("daoxing",i+2000);
  command("chat "+me->name()+"��ɳ�ӽ��������󽫣�");
message("channel:chat",HIY"������ն������������(guanyin pusa)��"+me->query("name")+"��������ȡ��[1;37m���߹أ�\n"NOR,users());
  tell_object (me,"��Ӯ����"+chinese_number(3)+"��"+
               chinese_number(i/4)+"��"+
               chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  me->save();
  destruct(ob); 
     return;
}
