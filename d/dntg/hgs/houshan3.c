// Room: /4world/houshan3

inherit ROOM;

void create ()
{
  set ("short", "��ɽ");
  set ("long", @LONG

����ɽ��ɽ�е�һС��ƽ�ء�Ҫ��ɽ�ô�������һƬ���ԡ���
������һƬ�����֣��Ƴγε�⨺�����Ȼ�Ѿ���͸��һ�����
Ʈ�������ˮ�����˳������������ֱ�������ֻ��������
�����ע�����㡣
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/ma-yuanshuai" : 1,
  __DIR__"npc/liu-yuanshuai" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"houshan2",
  "east" : __DIR__"houshan4",
  "north" : "/d/pansi/tao_in",
]));

  setup();
}

int valid_leave(object me, string dir)
{
	object mys, lys;
    if(dir=="east"){
        if(objectp(mys=present("ma yuanshuai", environment(me)))&&
           objectp(lys=present("liu yuanshuai", environment(me)))
           && living(mys) && living(lys) )
	return notify_fail("������Ԫ˧����һ��֨֨�ҽУ���ݺݵذ�����ס�ˡ�\n");
        if(objectp(mys=present("ma yuanshuai", environment(me)))&&living(mys))
	return notify_fail("��Ԫ˧����һ��֨֨�ҽУ���ݺݵذ�����ס�ˡ�\n");
        if(objectp(lys=present("liu yuanshuai", environment(me)))&&living(lys))
            return notify_fail("��Ԫ˧����һ��֨֨�ҽУ���ݺݵذ�����ס�ˡ�\n");
    }
    return ::valid_leave(me, dir);
}



