//Cracked by Roath
// snowcat 12 14 1997

inherit NPC;

#include <obstacle.h>

int do_tell ();

void create()
{
  set_name("��Ҷ����", ({ "jiaye zunzhe", "jiaye", "zunzhe" }));
  set("title", "��ɽ");
  set("gender", "����");
  set("age", 1000);
  set("attitude", "peaceful");
  set("str",40);
  set("per",40);
  set("max_kee", 2000);
  set("max_gin", 2000);
  set("max_sen", 2000);
  set("force", 2000);
  set("max_force", 2000);
  set("force_factor", 80);
  set("max_mana", 2000);
  set("mana", 2000);
  set("mana_factor", 80);
  set("combat_exp", 1200000);
  set("daoxing", 2500000);

  set_skill("literate", 90);
  set_skill("spells", 90);
  set_skill("buddhism", 90);
  set_skill("unarmed", 90);
  set_skill("jienan-zhi", 90);
  set_skill("dodge", 90);
  set_skill("lotusmove", 90);
  set_skill("parry", 90);
  set_skill("force", 90);
  set_skill("lotusforce", 90);
  set_skill("staff", 90);
  set_skill("lunhui-zhang", 90);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("parry", "lunhui-zhang");
  map_skill("staff", "lunhui-zhang");
  set("inquiry", ([
    "name" : "��ҶҲ��",
    "here" : "��ɽҲ��",
    "��ɽ" : "�ҷ�����֮��ɽҲ��",
    "������" : "�ҷ�����֮������Ҳ��",
    "����" : (: do_tell :),
    "����" : (: do_tell :),
    "��ȡ�澭" : (: do_tell :),
    "ȡ��" : (: do_tell :),
    "�澭" : (: do_tell :),
    "��" : (: do_tell :),
  ]));
  set("chat_chance_combat", 80);
  set("chat_msg_combat", ({
   (: cast_spell, "bighammer" :),
  }) );

  setup();
  carry_object("/d/obj/cloth/jia_sha")->wear();
}

void die()
{
  if (environment())
    message("sound", "\n"+this_object()->query("name")+"����һ��ͷ�����ޱߣ�\n\n", environment());

  set("eff_kee", 2000);
  set("eff_gin", 2000);
  set("eff_sen", 2000);
  set("kee", 2000);
  set("gin", 2000);
  set("sen", 2000);
  set("force", 2000);
  set("mana", 2000);
}



/*
void init ()
{
  call_out ("telling",10,this_player());
}

*/
int do_tell ()
{
  call_out ("telling",1,this_player());
  return 1;
}

int telling (object who)
{
  object me = this_object();

  int size = sizeof(obstacles);
  string *names = keys(obstacles);
  string *strs = allocate (size);
  int nb = 0;
  int i;

  if(!who) return 1;

  for (i = 0; i < size; i++)
  {
    strs[i] = "none";
  }

  for (i = 0; i < size; i++)
  {
    if (who->query("obstacle/"+names[i])!="done")
    {
      strs[nb] = obstacles[names[i]];
      nb++;
    }
  }

  if (nb == 0)
  {
    tell_object (who,me->query("name")+
                     "�����㣺��������ȡ�澭�����������е��ѹء�\n\n");
    who->set_temp("obstacle/lingshan_enter",1);
    if (environment(me)==environment(who) &&
        who->query("obstacle/reward") == 0)
      message_vision ("$N��$nһ�Ϲ����ҷ����룡\n",me,who);
  }
  else
  {
    tell_object (who,me->query("name")+"�����㣺��������ȡ�澭�����"+
                     chinese_number(nb)+"�أ�\n");
    strs = (string *)sort_array (strs, 1);
    for (i = 0; i < nb; i++)
    {
      tell_object (who,"    "+strs[i]+"\n");
    }
    tell_object (who,"\n");
  }
  return 1;
}

