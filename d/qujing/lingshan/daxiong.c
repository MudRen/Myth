// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "���۱���");
  set ("long", @LONG

���۱������̻Ի��������𣬸������������룬��ǽ�
���ܣ�������ǽ���ԧ��˫˫�Զԣ�������һ�����������
̨���ϱ���һ����ͨ���������߸���һƫ�š�

LONG);
  
  set("exits", ([
        "north"   : __DIR__"sanmen",
        "south"   : __DIR__"houdian",
        "west"   : __DIR__"zhenlou1",
        "east"   : __DIR__"baoge1",
      ]));
  set("objects", ([
        __DIR__"npc/rulai" : 1,
        __DIR__"npc/xiantong" : 2,
     ]));
  set("no_fight", 1);
  set("no_magic", 1);
  setup();
}

void init()
{
//
    add_action("do_drop", "drop");
    add_action("do_put", "put");
    add_action("do_get", "get");
}

int do_drop(string arg)
{
   object me=this_player();
   object obj;
   
   if( !arg ) return 0;
      
   if( !objectp(obj = present(arg, me)) )
          {  tell_object(me,"������û������������\n");
             return 1;
          }
  
   if ( me->query("rulaitask/kind") != "��")
          {  tell_object(me,"���������˵��������Ҫ����ô�Ҷ���������\n");
             return 1;
          }
          
    if( !obj->is_character() )
           {  tell_object(me,"���������˵��������Ҫ����ô�Ҷ���������\n");
             return 1;
          }
               
    else {    if( obj->is_corpse() )
                   {  tell_object(me,"���������˵��������Ҫ����ô�Ҷ���������\n");
                      return 1;
                   }
                   
              if( obj != me->query("rulaitask/guai") )
                   {   tell_object(me,"���������˵��������û�н����ܴ˹ֻ�������\n");
                       return 1;
                   }
          
               call_out ("accomplish",2,me,obj);
               return 0;
          }
}      

void accomplish(object me, object obj)
{
      if(!living(obj) && objectp(obj))
        {tell_room(this_object(),"������հ�"+obj->name()+"Ѻ����ȥ��\n\n");
        if(obj->query("question")=="done") me->set_temp("rulai_task",1);
         destruct (obj);
         me->set("rulaitask/accomplish",1);
         me->set("rulaitask/end_time",time());
         me->delete("rulaitask/get");
        }
       else return;
}


int do_get(string arg)
{
        string from;
        object me = this_player();
        object env;
        
        if( !arg ) return 0;
                
        if( sscanf(arg, "%s from %s", arg, from)==2 )
            {
                env = present(from, me);
                if(!env) env = present(from, environment(me));
                if(!env) return 0;
                if(env->is_character() && !living(env))
                      {  tell_object(me,"���������ҡ��ҡͷ��\n");
                         return 1;
                      }
            }
        
        else {
                env = present(arg, environment(me));
                if(!env) env = present(arg, environment(me)); // added by mudring@sjsh......
                if(! env) return 0; // added by mudring@sjsh......
                if(env->is_character() && !living(env))
                      {  tell_object(me,"���������ҡ��ҡͷ��\n");
                         return 1;
                      }
             }
                        
        return 0;
}               
int do_put()
{
        object me = this_player();
//
tell_object(me,"ͻȻ���ﴫ��һ��,���ʲô,�ߡ���\n");
 return 1;
}
