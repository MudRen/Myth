// dd by ddy of 1/3/97
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���");
        set ("long", @LONG
�⻧��լ�ӽṹ�Ͽ������൱����ģ���ʾ���⻧�˼���ǰ�ƺ�����
��������֪����һ����ҵ���ʼ˥���ˣ���������Ҳ��֮���ʧ�ޡ�
�����⻧�˼ҵ��������Ӹ������������ֺ��У�������ҵ��
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "hole" : "�����ƺ��Ǹ����أ��ܷ�(insert)��ʲô������\n",
]));

        set("exits", 
        ([ //sizeof() == 4
           "east" :__DIR__"beiyin3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("no_clean_up", 0);
        set("water", 1);
        setup();
//      replace_program(ROOM);
}

void init()
{
//    add_action("do_insert", "insert");
}
int do_insert(string arg)
{
        object mishi, ob, me;
        me=this_player();
        if( !arg )
                return notify_fail("��Ҫ��ʲô������\n");

        if( !arg || arg!="yao pai" || !(ob=present(arg, me)) || ob->query("name")!="ˮ������" )
                return notify_fail("�ƺ����зŲ������������\n");

        if( !(mishi = find_object(__DIR__"mishi1")) )
                mishi = load_object(__DIR__"mishi1");

        if( mishi = find_object(__DIR__"mishi1") ) 
        {
                set("exits/enter", __DIR__"mishi1");

                message_vision("$N��$n����С�ף�ֻ������������һ����ʯ�ƿ���¶������һ��ͨ�ڡ�\n", me, ob);
                message("vision", "��ʯ���˴����ƿ��ˡ���\n", mishi );
                mishi->set("exits/out", __DIR__"jiashan1");
                destruct(ob);
        call_out("close_down", 5);
        }
        return 1;
}

void close_down()
{
        object mishi;

        message("vision", "��ʯ����ֻص�ԭλ��\n", this_object() );
        if( mishi= find_object(__DIR__"mishi1")) {
        message("vision", "��ʯ����ֻص�ԭλ��\n", mishi);
        mishi->delete("exits/out");
        }

        delete("exits/enter");

}
