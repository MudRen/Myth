// Room: /u/mes/kitchen.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������֧�������ڴ���������һ����ܣ����ղ�Ϣ�������ﴫ������
��ȴ���ǹŹ֣������������������¡�ǽ�����Ÿ�ʾ(gaoshi)����
�հ߰ߣ��ּ���Ϊģ����
LONG);

  set("valid_startroom", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "gaoshi" : "����ȱ���������⣬����С�������ܻ������ͳ�����
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"dong2",
]));
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

  set("objects", ([ /* sizeof() == 1 */


//cut yanshu .��Ϊ�������һ����bug!
//һ���µ�newbie,����wdd,Ҫ�����������
//get һ��zhang men(��Ҫ��zhang men��������⣬�������������)
//Ȼ��sell,�õ��İ���:/d/qujing/wudidong/npc/obj/renroubao.c
//eat rou baozi��:eat rou baozi 
//������������ӣ�������ζ�س�����ȥ��> ��ͻȻ�е�������Щ�仯���ƺ��������ڻ���ʱ�ĵ���������һЩ��
//���� ���� ��һ����ǧ������ʮ�����ʮ����ʱ��                          ��
// ��zhang men����û���֮ǰ���������bug ��cut
//��lian���player�ṩ����������seng@2005-1-26

// 28    __DIR__"npc/yanshu": 1,
]) );
  setup();
    call_other("/obj/board/wudidong_b", "???");
}
void init()
{
    add_action("do_save", "save");
}
int do_save(string arg)
{
    object me=this_player();
    if (arg) return 0;
    if (me->query("family/family_name")!="�ݿ�ɽ�޵׶�")
    {
        me->save();
        tell_object(me, "����������ϡ�\n");
        return 1;
    }
    return 0;
}
