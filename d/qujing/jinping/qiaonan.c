// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����ٽ֣������ɼ������ŵƽ�ʣ�һ����������ζ�����Ǳ�
˳��Ʈ��������ˮ����������������������������ȥ������
���ǳ��

LONG);

  set("exits", ([
        "north"   : __DIR__"qiao",
        "south"   : __DIR__"xiaojie2",
      ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      dir == "north")
    return 0;

  return ::valid_leave (who, dir);
}


