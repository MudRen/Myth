//Cracked by Roath
// create by snowcat.c 2/8/1997

inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

һ���ɵ���̴ľ���������Ĵ��Ÿ߸����ض�������������
�������͸������䱦ʯ���������Ǵ��᳡��������������
��ǧ��������û�о���ˮ½���ʱ�����˲����������ڡ�

LONG);

  set("exits", ([
        "northdown"   : __DIR__"shuilu",
        "south"   : __DIR__"north",
      ]));

  setup();
}

int valid_leave (object who, string dir)
{
  if (wizardp(who))
    return ::valid_leave(who, dir);
  if (dir == "south")
    //return notify_fail ("�Բ���������ʦ��������ȥ��\n");
    return ::valid_leave(who, dir);
  return ::valid_leave(who, dir);
}



