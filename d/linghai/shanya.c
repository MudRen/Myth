//by dewbaby

//shanya   
#include <ansi.h> 
inherit ROOM; 
        
void create () 
       { 
         set ("short", YEL"Сɽ��"NOR); 
         set ("long", @LONG 
        
�߹�ï�����Թ���������֣��������ҵ���һ��
�ľ���С·�������������������ż���������
Ⱥ�Ĵ���ɹ���·�ľ�ͷ�Ǹ�Сɽ�£��䲻�ܶ���
ȴ��Ȼ���㲻�ҳ�������
LONG); 
       
        set("outdoors", 2); 
        set("exits", ([ /* sizeof() == 1 */ 
        "southdown" : __DIR__"shulin9",
        ])); 
       
        setup(); 
      }


      void init() 
      { 
          add_action("do_jump", "jump"); 
      } 
   int do_jump(string arg)
      {   object me; 
          me=this_player(); 
       if(! arg || arg !="shanya") 
                 return notify_fail("��Ҫ��������?\n");

       if (me->is_busy() || me->is_fighting())
                 return notify_fail("����æ����,���ż�!\n");
       if (arg == "shanya") {
               message("vision", me->name() + "��������ɽ���С�\n", environment(me), ({me}));
  }
              if( ((int)me->query("kee") <= 400)&& 
              ((int)me->query("sen") <= 500)&&
              ((int)me->query("int") < 40) ) 
                 return
      message_vision(HIR"��ֻ��������һ��������������!\n"NOR,me); 
          me->receive_damage("kee",250);
           me->receive_wound("kee", 250);
          me->add("force",-200);
          me->start_busy(3);
          me->save();
   {
           message_vision(HIW"$N���Լ��������ģ�������������������ɽ�¡�\n"NOR, me); 
           me->move(__DIR__"jinse"); 
           message_vision("$N���������������� \n", me); 
           return 1; 
      } 
}

