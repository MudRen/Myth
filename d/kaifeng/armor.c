//Cracked by Roath
// create by snowcat.c 2/8/1997

inherit ROOM;

void create ()
{
  set ("short", "���׿�");
  set ("long", @LONG

���׿���һ������̴ľ���Ϸ��Ŵ��СС�ı�׼���׻��ߣ���
���������������ʦ��ȡ���ʵĿ��׻��ߡ���ʦ�ɴ�̴ľ����
����(take)���߷ַ����μӴ������֡������Ϸ��У�
  ���ף�      armor
  ���ƣ�      shield
  ѥ�ӣ�      boots
  ָ�ף�      finger
  ���ף�      hands
  ͷ����      head
  Χ����      neck
  ���磺      surcoat
  ������      waist
  ����      wrists

LONG);

  set("exits", ([
        "west"   : __DIR__"east",
      ]));

  setup();
}

void init ()
{
  add_action ("do_take","take");
  add_action ("do_take","na");
}

int do_take (string arg)
{
  object who = this_player();
  object ob;

  if (! wizardp(who))
    return notify_fail ("�Բ���������ʦ�������ö�����\n");

  if (! arg)
    return notify_fail ("��Ҫ��ʲô��\n");
  if (arg == "armor")
    ob = new ("/d/obj/armor/standard/armor");    
  else if (arg == "shield")
    ob = new ("/d/obj/armor/standard/shield");    
  else if (arg == "boots")
    ob = new ("/d/obj/armor/standard/boots");    
  else if (arg == "finger")
    ob = new ("/d/obj/armor/standard/finger");    
  else if (arg == "hands")
    ob = new ("/d/obj/armor/standard/hands");    
  else if (arg == "head")
    ob = new ("/d/obj/armor/standard/head");    
  else if (arg == "neck")
    ob = new ("/d/obj/armor/standard/neck");    
  else if (arg == "surcoat")
    ob = new ("/d/obj/armor/standard/surcoat");    
  else if (arg == "waist")
    ob = new ("/d/obj/armor/standard/waist");    
  else if (arg == "wrists")
    ob = new ("/d/obj/armor/standard/wrists");    
  else
    return notify_fail ("��Ҫ��ʲô��\n");
  message_vision ("$N�Ӽ���������$n��\n",who,ob);
  ob->move(who);
  return 1;
}



