// Room: /u/mimi/zhuziguo/wall.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create()
{
  set ("short", "�˹�ͤ");
  set ("long", @LONG
    �����ǰ׹Ƕ�������ʱ��Ϣ�ĵط�������ͤ�ö�����
�˹Ǵ���ɣ�ͤ�����þŸ����ú;Űپ�ʮ�Ż�����
���ɣ��ĸ�ͤ���������ô��ȹǶ������ġ��������Ե�
��ԩ�겻�ó���,��ۼ��˵أ�����������������Ҳң�
����ɭɭ��

LONG);

  set("exits", ([ /* sizeof() == 1 */
    "northup" : __DIR__"dongkou",
    "westdown" : __DIR__"guangchang",
  ]));
  set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/baigujiangjun" : 1,
  ]));
  set("outdoors", __DIR__"");                   
  setup();
}

int valid_leave (object who, string dir)
{
  object ob = present ("baigu jiangjun", environment(who));
  if (dir == "northup" && ob && living (ob))
      return notify_fail (ob->query("name")+"�ȵ���߾,�����������ˣ������Ұ׹Ƕ�����\n");
  
  if(! interactive (who) &&
      who->query("xiaoyao") == "xiaoyao" &&
       dir == "southdown")
    return 0;

  return ::valid_leave(who, dir);
}
