// created by snowcat on 4/11/1997
// room: hongyan

inherit ROOM;

void create ()
{
  set ("short", "����̶");
  set ("long", @LONG

һ������±ڽ�һ��̶ˮ���ƣ�������һ������ͨ��ɽ�⡣����
�����ɽ���Ѿ���һ�ξ����ˣ�������̶ˮ�ߣ����˾����ر���졣
�����ס����һ�������Ŀ�������

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"shanwai",
  "west" : "/d/qujing/jilei/shan4",
]));
  set("outdoors", "firemount");

  setup();
}

int valid_leave (object me, string dir)
{
/*
  if (dir=="northwest" && 
      me->query("obstacle/firemount") != "done")
  {
    tell_object(me,"��̧��ţ�ȴ��ôҲ���������ӡ���\n");
    return notify_fail("����ɽ��һ��û�й������������������ȥ��\n");
  }
*/
  return 1;
}
