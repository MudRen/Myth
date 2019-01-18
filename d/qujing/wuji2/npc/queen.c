inherit NPC;

int give_jing();

void create()
{
  set_name("����", ({"wang hou", "hou", "queen"}));
  set ("long", "�ڼ������������ճ�ü��������˼���ء�\n");
  set("title", "�ڼ���");
  set("gender", "Ů��");
  set("age", 40);
  set("combat_exp", 100000);
  set_skill("blade", 20);
  set_skill("dodge", 20);
  set_skill("parry", 20);
  set_skill("unarmed", 20);
  set_skill("force", 20);
  set("max_sen", 500);
  set("max_kee", 500);
  set("max_force", 500);
  set("force", 100);
  set("force_factor", 4);

  set("inquiry", ([ "wang": "��ҹ��������,��һ��һ��,�����Ӧ",
                    "����": "��ҹ��������,��һ��һ��,�����Ӧ",
                    "king": "��ҹ��������,��һ��һ��,�����Ӧ",
                    "����": "�����������ʥˮһƿ,�ɾȱ���",
                    "pusa": "�����������ʥˮһƿ,�ɾȱ���",
                    "ʥˮ": (: give_jing :),
                    "shengshui": (: give_jing :),
                 ]) );

  setup();
 
  carry_object("/d/obj/cloth/gongpao")->wear();
}

int give_jing()
{
  object ob	;
  object me=this_object();
  object who=this_player();

  if (who->query("obstacle/qujing")!="ren")
    {
    message_vision("����ʥˮֻ��ȡ����,����....\n",me);
    return 1; 
    }
 
  if (who->query("obstacle/wuji")=="done"|| me->query("have_gived")==1)
    {
    message_vision("$N�ɻ��˵��:���ƺ��������˰�?\n",me);
    return 1;
    }

  ob = new ("d/qujing/wuji2/obj/jing");
  message_vision ("\n$N��$n˵���������ˣ��������վȵñ��¹�����\n",me,who);    message_vision ("\n˵��$Nȡ��һϻ�ӣ��ó�һСƿ����\n",me,who);  
  ob->move(me);
  me->command_function("give "+who->query("id")+" jing");
  me->set("have_gived",1);

  return 1;
}

