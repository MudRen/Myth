// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

һ����¥������������ʯǽ�����б�ʿ��ǹѲ�ߡ�ǽ����һ��
���Ļ��ǺӴ����Ѿ������ˣ����ϼ����������š���¥����
һ���ӣ������ɿ�����

LONG);

  set("exits", ([
        "north"    : __DIR__"dalu3",
        "south"    : __DIR__"dalu4",
        "west"    : __DIR__"jiedao7",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

int valid_leave (object who, string dir)
{
  if (dir == "west")
    return ::valid_leave (who, dir);

  if (interactive (who))
    return ::valid_leave (who, dir);

  return 0;
}
