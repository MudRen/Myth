// �������� "�������� ������" by Calvin

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string kick_back();

void create()
{
  set_name(MAG"������"NOR, ({ "wu yazi", "wu", "wuyazi","yazi","tianshen","wu" }));

  set("gender", "����");
  set("age", 100);

  set("str", 20);
  set("per", 130);
  set("cor", 30);
  set("cps", 75);
  set("kar", 100);
  set("int", 40);
  set("con", 40);
  set("spi", 40);

  set("long","
������ǰ����������һֻ���,��������ת��Ϊ����������

");
  set("title",MAG"Ц������"NOR);
  set("combat_exp", 5000000);
  set("daoxing", 5000000);

  set_skill("literate", 350);
  set_skill("unarmed", 350);
  set_skill("force", 350);
  set_skill("lengquan-force", 350);
  set_skill("axe", 350);
  set_skill("dodge", 350);
  set_skill("parry", 350);
  set_skill("sanban-axe", 350);
  set_skill("bawang-qiang", 350);
  set_skill("spells", 350);
  set_skill("baguazhou", 350);
  set_skill("jinglei-mace", 350);
  set_skill("mace", 350);
 set_skill("spear", 350);
  set_skill("yanxing-steps", 350);

  map_skill("force", "lengquan-force");
  map_skill("spells", "baguazhou");
  map_skill("axe", "sanban-axe");
  map_skill("parry", "sanban-axe");
  map_skill("dodge", "yanxing-steps");
  map_skill("spear", "bawang-qiang");

  set("max_sen", 5000);
  set("max_kee", 5000);
  set("force", 2500); 
  set("max_force", 2500);
  set("force_factor", 140);
  set("max_mana", 3000);
  set("mana", 3000);
  set("mana_factor", 150);

  set("inquiry", ([
        "name"    : "С�����������һ'Ц������ ������'��",
        "here"    : "��������������,Ҳ����ǧ���졣",
        "��ȥ"    : (: kick_back :),
]) );

  create_family("������", 1, "��");

  setup();
  carry_object("/d/9ct/zb/axe")->wield();
  carry_object("/d/9ct/zb/kui")->wear();
}

void attempt_apprentice(object me)
{
  int effstr=(int)(me->query("str")+me->query_skill("unarmed",1)/10-2);
  string myrespect=RANK_D->query_respect(me);

  if (wizardp(me) && me->query("env/override"))
  {
        command("recruit "+me->query("id"));
        return;
  }
    if (effstr<20)
  {
      command("say "+myrespect+"�ı�������Щ����������ѧ����");
      return;
 }
  command("nod");
  command("say ����"+myrespect+"�����������֮ʱ��,���Ҿ����°�!\n");
  command("recruit " + me->query("id") );
  return;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "fighter");
    ob->set("title",HIC"���������ʹ"NOR);
}

