//shulin ����

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

������ͨ������ʹ��ĵڶ�������,��������վ�����ʿ��
���ϵ��깬���źò�����,�������ϰ��յĽ���,��������
LONG);

  set("objects", ([ /* sizeof() == 2 */
      "/d/huanggong/npc/weishi" : 2,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 4 */
      "north" : "/u/calvin/����/����/�깬����",
                 "southup" : "/u/calvin/����/����/Ǭ��",
        ]));

  setup();
}

int valid_leave(object me, string dir)
{
    if(me->query("office_number")) return 1;
        if (dir == "southup" ) {
        return notify_fail("�㶼���ǵ��ٵ�,���������߰ɣ�\n");
}
 return 1;
}
