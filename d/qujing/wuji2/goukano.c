//  ROOM:  /d/qujing/wuji/guankou.c �ؿ� �ڼ����ͳ��ٵĽ���
inherit ROOM;

void create ()
{
  set ("short", "�ڼ����ؿ�");
  set ("long", @LONG

�ڼ����Ĺؿ�,�������ǳ��ٹ�.�����������������̲�.����һ��
��������.�߽��ػ�Ҳ�ֵ�����,ֻ����ͨ�����ȴ�ǲ�����.
LONG);

  set("exits", ([ /* sizeof() == 2 */
    "east" : __DIR__"shandao3",
    "west" : __DIR__"shandao4",
  ]));

  setup();
}

int valid_leave (object who, string dir)
{
  if (dir == "west")
  {
    if (who->query("obstacle/qujing")=="ren")
    {
      if (who->query("obstacle/wuji")!="done")
      {
      return notify_fail ("һ��С����ס��˵��:��ȡ������ס,"
 		+"Ҫ���ؿ��»���ͨ����뺡���\n");
      }
      else
      {
      tell_object(who,"��������һ��ߺ�:����ȥ����·;ңԶ,ʥɮ���ء���\n")  ;
      }
    }
  }
  return ::valid_leave(who, dir);
}

