
#include <ansi.h>
inherit NPC;

void create()
{
  string name, id;

  set_name("�����ʿ", ({ "jinjia weishi", "guard", "weishi" }) );
  set("gender", "����" );
  set("long", "

һ���������ݵ��콫������ĸ֮�����������ء�
����ְ�أ����Ὣ�κ�û��������˽�����ڡ�
");
  set("age", 35+random(10));
  set("attitude", "peaceful");
  set("str", 80);
  set("int", 25);
  set("per",21);
  set("combat_exp",100000);
  set("daoxing",100000);
  set("force",500);
  set("max_force",500);
  set("force_factor", 50);
  set("max_kee", 900);
  set("max_sen", 600);
  set("max_mana", 400);
  set("mana", 400);
  set("mana_factor", 20);
  set_skill("unarmed",99);
  set_skill("dodge",99);
  set_skill("parry",99);
  set_skill("spear",99);
  set_skill("stick",99);
  set_skill("sword",99);
  set_skill("axe",99);
  setup();
  carry_object("/d/obj/armor/jinjia")->wear();
  switch(random(4)) {
     case 0:
            carry_object("/d/obj/weapon/stick/bintiegun")->wield();
            break;
     case 1:
            carry_object("/d/obj/weapon/sword/tiejian")->wield();
            break;
     case 2:
            carry_object("/d/obj/weapon/spear/tieqiang")->wield();
            break;
     default :
            carry_object("/d/obj/weapon/axe/bigaxe")->wield();
            break;
  }
}

void unconcious() {die();}

int accept_object(object me, object ob)
{

   if ((string)ob->query("id")!="invitation letter") return 0;
   call_out("verify",1,me);  
   return 1;
}      

void verify(object me) {

  if (me->name()!="��Ŵ���") {
    tell_object(me,"��һ̧ͷ�����ֽ����ʿ����һ��������Ŀ������Ͷ����\n");
    command("hmm");
    command("say ������������Ǹ���Ŵ��ɵģ���ô������������");
    message_vision(CYN"$N�ŵû겻���壬����˵�������Ҽ�ģ��ҵ��ϼ�ģ��ҡ�����\n"+
        "��û˵�꣬��һ���̵ض���˽��䡣\n"NOR,me);
    return;
  }

  command("say ԭ���ǳ�Ŵ��ɼݵ���");
  command("bow daxian");
  command("say ������롣����");
  me->set_temp("yaochi_pass",1);
}
