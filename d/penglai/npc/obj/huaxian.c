//Cracked by Roath

#include <ansi.h>
#include <combat.h>

inherit NPC;
#include <flowers.h>

string name;

void create()
{
  name=flowers[random(sizeof(flowers))];
  set_name(name+"����", ({ "hua xianzi","xianzi","xian" }) );
  set("long",@LONG
һλƷò���������ʸ��ŵĻ����ӣ�����ɢ����һ�����㣬
�ȷǱ��꣬�ַ��̴���ƻ�����ǻ��㣬ʱ�̱任�����а�
��������
LONG);
  set("gender", "Ů��");
  set("age", 20);
  set("str", 10+random(21));
  set("dex", 10+random(21));
  set("int", 10+random(21));
  set("cor", 10+random(21));
  set("spi", 10+random(21));
  set("con", 10+random(21));  
  set("per", 10+random(21));

  set("combat_exp", 10000);
  set("daoxing", 10000);

  set_skill("unarmed", 80);
  set_skill("parry", 80);
  set_skill("dodge", 80);
  set_skill("moondance",80);
  set_skill("force", 180);
  set_skill("spells", 180);
  set_skill("moonshentong",180);
  map_skill("spells","moonshentong");
  map_skill("dodge","moondance");

  set("max_kee", 1000);
  set("max_sen", 1000);
  set("mana", 4000);
  set("max_mana", 1000);
  set("mana_factor", 60);
  set("force", 2000);
  set("max_force", 1000);
  set("force_factor", 120);
  
  setup();
  if (clonep())  carry_object("/obj/loginload/skirt")->wear();
  if (clonep())  carry_object("/obj/loginload/shoes")->wear();

}

void init() {
}
