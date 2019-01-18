// by snowcat

inherit NPC;

#include <reporting.h>

void create()
{
  set_name("��ʿ��", ({ "zhang shiheng", "zhang", "shiheng", "da chen" }));
  set("title", "��");
  set("gender", "����");
  set("age", 60);
  set("per", 30);
  set("combat_exp", 300000);
  set_skill("force", 80);
  set_skill("spells", 80);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set("gin", 3000);
  set("max_gin", 3000);
  set("kee", 3000);
  set("max_kee", 3000);
  set("sen", 3000);
  set("max_sen", 3000);
  set("force", 1000);
  set("max_force", 1000);
  set("mana", 1000);
  set("max_mana", 1000);
  set("force_factor", 80);
  setup();
  carry_object("/d/obj/cloth/jinpao")->wear();
}

void reward (object who)
{
  object me = this_object ();
  int points = who->query_temp("quest/reward_point");
  int limit = 40;
  int i = 10;
  string str;
  string name;
  string channel = "sldh";
  string *channels = who->query("channels");

  if ( !pointerp(channels) || !sizeof(channels) )
    channels = ({ channel });
  else if (member_array(channel, channels) == -1)
    channels += ({ channel });

  who->set("channels",channels);

  while (i--)
  {
    switch (random(8))
    {
      case 0: 
      {
        if (who->query_str() < limit)
        {
          str = "apply/strength";
          name = "����";
          break;
        }
      }
      case 1: 
      {
        if (who->query_cor() < limit)
        {
          str = "apply/courage";
          name = "��ʶ";
          break;
        }
      }
      case 2: 
      {
        if (who->query_int() < limit)
        {
          str = "apply/intelligence";
          name = "����";
          break;
        }
      }
      case 3: 
      {
        if (who->query_spi() < limit)
        {
          str = "apply/spirituality";
          name = "����";
          break;
        }
      }
      case 4: 
      {
        if (who->query_cps() < limit)
        {
          str = "apply/composure";
          name = "����";
          break;
        }
      }
      case 5: 
      {
        if (who->query_per() < limit)
        {
          str = "apply/personality";
          name = "��ò";
          break;
        }
      }
      case 6: 
      {
        if (who->query_con() < limit)
        {
          str = "apply/constitution";
          name = "����";
          break;
        }
      }
      case 7: 
      {
        if (who->query_kar() < limit)
        {
          str = "apply/karma";
          name = "��Ե";
          break;
        }
      }
    }
  }
  if (! str)
  {
    str = "apply/personality";
    name = "��ò";
  }
  
  points = 2;
  message_vision ("$N��$nһ�ݣ������б��´���ּ����"+RANK_D->query_respect(who)+
                  chinese_number(points)+"��"+name+"��\n",me,who);
/*  
  command (channel+" "+who->query("name")+who->query("quest/reason")+"������ּ����"+
           chinese_number(points)+"��"+name+"��");
*/  
  who->add("quest/gain/"+str,points);
  reporting (who, who->query("quest/reason"), points, "��"+name);

  who->add_temp(str,points);
}


