// literate.c

inherit ITEM;
inherit F_SAVE;

void create()
{
  set_name("�����־���", ({"wuzi jing", "jing", "book"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("material", "paper");
    set("unique", 1);
    set("treasure", 1);
    set("value", 0);
    set("long", "һ�����������־���\n");
// ����������Ͻ��޸�
// mudring ...
                set("no_drop", "�ⶫ�����ܶ���\n");
                set("no_put", "��ϧ���ɡ�\n");
                set("no_give", "�ⶫ���������ˡ�\n");
                set("no_get", "�ⶫ���첻������\n");

  }
    setup();
}

void init ()
{
  object me = this_object();
  object who = this_player();

  add_action ("do_read", "read");
  add_action ("do_read", "study");
  add_action ("do_read", "du");
  add_action ("do_decide", "decide");
        remove_call_out("do_melt");
        call_out("do_melt", 1);

  if (! me->query("my_owner") &&
      interactive (who))
    me->set("my_owner",who->query("id"));
}

void do_melt()
{
        if(this_object()) call_out("melt", 10);
}

void melt()
{
  object me = this_object();
  object who = this_player();
if (!me) return ;

  if (!me->query("my_owner") && me->query("my_owner") != who->query("id"))
  {
    tell_object (who,"�Ȿ�������ô��\n");
    destruct(this_object());
    return;
  }

}
void set_skill (string str)
{
  set("skill", ([
                "name": str,
                "exp_required": 1000000,
                "sen_cost": 25,
                "difficulty": 25,
                "max_skill": 300,
  ]));
}

mapping skills = ([
  "archery": "��������",
  "axe": "��������",
  "blade": "��������",
  "dagger": "�̱���",
  "dodge": "�����Ṧ",
  "fork": "�����淨",
  "hammer": "��������",
  "mace": "����ﵷ�",
  "parry": "����ж��֮��",
// : 88    "rack": "�����ٷ�", ����
    "rake": "�����ٷ�",
  "spear": "����ǹ��",
  "staff": "�����ȷ�",
  "stick": "��������",
  "sword": "��������",
  "throwing": "����ʹ��",
  "whip": "��������",
  "unarmed": "�˻���֮��",
  "force": "�ڹ��ķ�",
  "spells": "����",
  "literate": "����ʶ��",
]);

void show_skills ()
{
  int i;
  int size = sizeof (skills);
  string *strs = keys(skills);

  write ("�����ѡ�����¼��ܣ�\n");
  strs = (string *)sort_array (strs, 1);
  for (i = 0; i < size; i++)
  {
    write ("  "+strs[i]+": "+skills[strs[i]]+"\n");
  }
}

int do_decide (string arg)
{
  object me = this_object();
  object who = this_player();
  string *strs = keys(skills);
  string str;
  int i;
  int size = sizeof (skills);
 
  if (me->query("my_owner") != who->query("id"))
  {
    tell_object (who,"�Ȿ���鲻����ġ�\n");
    return 1;
  }

  if (who->query("obstacle/book"))
  {
    str = skills[who->query("obstacle/book")];
    tell_object (who,"�����Ѿ��������־�ѧϰ"+str+"�ˡ�\n");
    return 1;
  }

  for (i = 0; i < size; i++)
  {
    if (arg == strs[i])
    {
      str = skills[arg];
      break;
    }
  }

  if (! str)
  {
    show_skills ();
    return 1;
  }

  who->set("obstacle/book",arg);
  me->set_skill(arg);
  tell_object (who,"������Ӵ������־�ѧϰ"+str+"��\n");
  tell_object (who,"����Խ�"+str+"ѧϰ�����ټ���\n");
  who->save();
  return 1;
}

int reading (object me, object book)
{
  mapping skill;
  int cost, my_skill;

  if (environment(me)->query("no_fight") && 
      environment(me)->query("no_magic"))
    return notify_fail("��ȫ���ڽ�ֹ������\n");
                    
  if (me->is_fighting())
    return notify_fail("���޷���ս����ר�������ж���֪��\n");

  if (me->is_busy() || me->query_temp("pending/exercising"))
    return notify_fail("��������æ���ء�\n");

  if( !me->query_skill("literate", 1) )
    return notify_fail("���Ǹ���ä����ѧѧ����ʶ��(literate)�ɡ�\n");

  message_vision ("$N��ר�ĵ��ж�$n��\n",me,book);
  
  skill = book->query("skill");
  my_skill=me->query_skill(skill["name"],1);

  if ((int)me->query("combat_exp") < skill["exp_required"] ||
      ((string)SKILL_D(skill["name"])->type()=="martial"
      && my_skill*my_skill*my_skill/10>(int)me->query("combat_exp")))
  {
    write("��ĵ��в���������ô��Ҳû�á�\n");
    return 1;
  }

  notify_fail("����Ŀǰ����������û�а취ѧ������ܡ�\n");
  if (!SKILL_D(skill["name"])->valid_learn(me))
    return 0;

  cost = skill["sen_cost"] + skill["sen_cost"] 
         * (skill["difficulty"] - (int)me->query_int())/20;
  if ((int)me->query("sen") < cost)
  {
    write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
    return 1;
  }

  if( me->query_skill(skill["name"], 1) > skill["max_skill"] )
  {
    write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
    return 1;
  }

  me->receive_damage("sen", cost);

  if (!me->query_skill(skill["name"], 1))
    me->set_skill(skill["name"], 0);
  me->improve_skill(skill["name"], (int)me->query_skill("literate", 1)/5+5);
  write("���ж��й�" + to_chinese(skill["name"]) + "�ļ��ɣ��ƺ��е��ĵá�\n");
  return 1;
}

int do_read (string arg)
{
  object me = this_object();
  object who = this_player();

  if (! arg ||
      present (arg,who) != me)
    return notify_fail ("��Ҫ��ʲô��\n");

  if (me->query("my_owner") != who->query("id"))
  {
    tell_object (who,"�Ȿ���鲻����ġ�\n");
    return 1;
  }

  if (! me->query("skill"))  
  {
    if (who->query("obstacle/book"))
      me->set_skill(who->query("obstacle/book"));
    else
    {
      tell_object (who,"��ʹ��decide�����������þ���ѧϰʲô��\n");
      return 1;
    }
  }
  return reading (who,me);
}
