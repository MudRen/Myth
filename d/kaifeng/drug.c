//Cracked by Roath
// create by snowcat.c 2/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��ҩ��");
  set ("long", @LONG

��ҩ������һ������̨�����и�������ҩ��ҩ��ҩ�ۣ�����
��������������ʦ��ȡ���˵�ҩ���ʦ�ɴ�̨����(take)ҩ
�ַ����μӴ������֡�̨���Ϸ��У�
  ��ҩ��          jinchuang
  ��Ԫ����          hunyuan
  ��ת���굤��      dan

LONG);

  set("exits", ([
        "north"   : __DIR__"south",
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
  if (arg == "jinchuang")
    ob = new ("/d/obj/drug/jinchuang");    
  else if (arg == "hunyuan")
    ob = new ("/d/obj/drug/hunyuandan");    
  else if (arg == "dan")
    ob = new ("/d/obj/drug/dan");    
//  else if (arg == "huanyang")
//    ob = new ("/d/obj/drug/huanyang");    
  else
    return notify_fail ("��Ҫ��ʲô��\n");
  message_vision ("$N��̨������$n��\n",who,ob);
  ob->move(who);
  return 1;
}



