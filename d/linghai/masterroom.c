//by dewbaby
//masterroom
  
#include <ansi.h> 
inherit ROOM; 
        
void create () 
       { 
         set ("short", HIW"����ʯ��"NOR); 
         set ("long", @LONG 
        
����˻���ʯ�ң���ֻ����һ��̹Ǻ�����ͷ����
����������ȫ��ԭ����������������Ѩ�����·���
Ҫ��������ȥ���ƺ�ֻ�ܶ��־�·(dig road)�ˡ��
LONG); 
        
         
        set("exits", ([ /* sizeof==1  */
        "out":__DIR__"house1",        
        ])); 

        setup(); 
}
void init()
{
    add_action("do_dig","dig");

}
int do_dig(string arg)
{
    object me = this_player();
    if (!arg || arg !="road")
            return notify_fail("��Ҫ������?\n");
    if (me->is_busy() || me->is_fighting())
            return notify_fail("����æ����������!\n");
     if ((int)me->query_skill("force",1) <200)
    return notify_fail("����ڹ�������,�������»�����ԭ��!\n");
    if ((int)me->query("sen",1) < 400)
    return notify_fail("��ľ��񲻹�,�޷��ڵض�!\n");
         if( arg=="road"){ 
    if (random(me->query_str()) <= 20 )
    message_vision(me->name() + "�����ڹ�������������˫�֣��ڵ�������������\n",me); 
    tell_object(me,"�������΢΢����һ�����������ڵ�������������\n"NOR);
    me->start_busy(5);
    remove_call_out("out1");
    call_out("out1", 6, me);
    return 1;
}
else {
     message("vision", me->name() +"������΢΢����һ�����������ڵ�������������\n",environment(me),({me}));
     tell_object(me,"�������΢΢����һ�����������ڵ�������������\n"NOR);
}
     tell_object(me,HIW"\n����ǰ��Ȼһ��!\n\nԭ�����Ѿ�Ϊ�Լ��������·!\n"NOR);
     me->move("/d/city/center");
     me->start_busy(3);
    message_vision(me->name() + "�ӵص������Ծ�˳�������·������һ����\n",me); 
     return 1;
}
void out1(object me)
{          tell_object(me,"\n�����˫���е���ʹ,��Ϊ������,ֻ�ü����ڡ�\n"NOR); 
     me->start_busy(5);
     remove_call_out("out");
     call_out("out",3,me); 
}
void out(object me)
{
     tell_object(me,"\n�����˫���е���ʹ����Ϊ��������ֻ�ü����ڡ�\n"NOR);
     me->move("/d/city/center");
    message_vision(me->name() + "�ӵص������Ծ�˳�������·������һ����\n",me); 
}

    
