// Room: baigushan.c  writted by smile 12/10/1998

inherit ROOM;

void create ()
{
  set ("short", "�׹�ɽ");
  set ("long", @LONG

    ������ǰ׹�ɽ�ˡ���������������ɽͷ���ȷ������
���٣�·����ᾰ׹ǣ��Ųȿն����ã�����ͷƤһ���飬
�������١�
    ɽͷ���Ʈ�裬ԶԶ��ȥ�������ƺ�����һ�����İ�
�֡������������£�ɢ��������Ĺ�â����ɽ����һ��ͤ
�ӣ�����ԼԼ�м�����Ӱ�ڻζ���
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
  "northup" : __DIR__"broad",
  "southdown": __DIR__"sanchakou",
]));

  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      who->query("xiaoyao") == "xiaoyao" &&
      dir == "southdown")
    return 0;
  return ::valid_leave (who, dir);
}

