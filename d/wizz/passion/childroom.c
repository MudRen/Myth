inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "�׶�԰�ܲ�");
        set("long", @LONG
    �����������߿�վ������ֱ�������߿��׶�԰�İ��´���
԰���͸���Ա��ƽʱ����������������ģ�
    ǽ��һ��ֵ�ձ������look biao����������˭��ֵ
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/city/kezhan",
]));
        set("objects", ([

                        ]) );
        set("item_desc", ([
                 "biao": @TEXT
                �׶�԰ֵ�ձ�
                ����¥        ����
                ����          ����19��-22��
                ������ʹ      ���� 11-7
                ������      ʱ��δ��
                �������ʫ    ʱ��δ��
TEXT
        ]) );
set("valid_startroom", 1); 
set("no_time",1);  
set("no_fight", 1);  
set("no_magic", 1);  
               setup();
        call_other( "/obj/board/youeryuan_b", "???" );
}

void init()   
{
object me=this_player();   
if(userp(me) && me->query("id")!="blpoemde" && me->query("id")!="hjabc" && me->query("id")!="hqfa" && me->query("id")!="xsld" && me->query("id")!="ping" && me->query("id")!="yuexin" && me->query("id")!="firegirl" && me->query("id")!="qidi" && !wizardp(me) )   
{
message_vision("\n�Բ����������׶�԰��Ա���벻Ҫ���Դ��룡\n\n",me); 
me->move("/d/city/kezhan");   
}



// passion add xixi
        add_action("do_swim", "swim");
}

int do_swim()
{
        object me = this_player();
message_vision(HIY "$Nһ����û�ˡ�\n" NOR, me);
        me->move("/u/ffff/workroom");
        message_vision(HIY "ֻ��$Nʪ�����ش����ϵ���������\n" NOR, me);
        return 1;
}


