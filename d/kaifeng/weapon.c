//Cracked by Roath
// create by snowcat.c 2/8/1997

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

��������һ�Ż��̴ľ���Ϸ��Ÿ��ָ����ı�׼�����������
������������ʦ��ȡ���ֵı�������ʦ�ɴ�̴ľ��������(take)
�����ַ����μӴ������֡������Ϸ��У�
  ��師��    axe
  �ֵ���      blade
  �ֲ棺      fork
  ��ͭﵣ�    mace
  �ְң�      rake
  ��ǹ��      spear
  ���ȣ�      staff
  ��������    stick
  ������      sword
  ���ʯ��    throwing
  Ƥ�ޣ�      whip
  ذ�ף�      dagger
  ������      hammer

LONG);

  set("exits", ([
        "east"   : __DIR__"west",
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
  if (arg == "axe")
    ob = new ("/d/obj/weapon/standard/axe");    
  else if (arg == "blade")
    ob = new ("/d/obj/weapon/standard/blade");    
  else if (arg == "dagger")
    ob = new ("/d/obj/weapon/standard/dagger");    
  else if (arg == "fork")
    ob = new ("/d/obj/weapon/standard/fork");    
  else if (arg == "hammer")
    ob = new ("/d/obj/weapon/standard/hammer");    
  else if (arg == "mace")
    ob = new ("/d/obj/weapon/standard/mace");    
  else if (arg == "rake")
    ob = new ("/d/obj/weapon/standard/rake");    
  else if (arg == "spear")
    ob = new ("/d/obj/weapon/standard/spear");    
  else if (arg == "staff")
    ob = new ("/d/obj/weapon/standard/staff");    
  else if (arg == "stick")
    ob = new ("/d/obj/weapon/standard/stick");    
  else if (arg == "sword")
    ob = new ("/d/obj/weapon/standard/sword");    
  else if (arg == "throwing")
    ob = new ("/d/obj/weapon/standard/throwing");    
  else if (arg == "whip")
    ob = new ("/d/obj/weapon/standard/whip");    
  else
    return notify_fail ("��Ҫ��ʲô��\n");
  message_vision ("$N�Ӽ���������$n��\n",who,ob);
  ob->move(who);
  return 1;
}



