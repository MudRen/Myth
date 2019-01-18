// Room: /u/mon/poem/yard by mon@xyj 5/9/97
inherit ROOM;
#include <ansi.h>;

int POEMS=319;
string this_place="/d/ourhome/honglou/yard2";
//need to change above line if this room is moved to another place.

string author,title,*poem;
string author1,title1,*poem1;
int length,length1,running;
string current,current_all,last,last_all;
string curr_show;
int index,chance;
int poem_index,answerd,ans_curr,ans_last;

void new_poem();
void copy_to_old();
void do_test();
void do_init(object me);
void poem_reward(object me,string arg);
void poem_reward1(object me);
void poem_penalty(object me);
int find_newline();
string enscript(string arg);


void create ()
{
  set ("short", "޿��Ժ");
  set ("long", @LONG

��������޿������Է����޵���ҷ�����������ݣ�����һ���㡣
�����������������������λ��ȡ�˭ν��������л�����γ���


����������������񰸣�һ����ͷ���Ų��ڲ��۸�ɫ��ߣ�һ���������
��īֽ�⡣����һ�Ŵ�ֽ�ϣ�ī��δ�ɣ����ɷ����д��Щʲô(poem)��

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"miner.c",
  "east":__DIR__"lihuashu.c",
  "south" : __DIR__"cave",
  "north" : __DIR__"main",
]));

  set("no_fight", 1);
  set("no_magic", 1);

  set("objects", ([
    __DIR__"npc/poemgirl": 1,
  ]));

  setup();

  remove_call_out("do_test");
  poem_index=1;
  running=0;

}

void init()
{   
     add_action("do_answer","answer");
     add_action("do_author","author");
     add_action("do_look","look");
     
     call_out("do_init",1,this_player());

     if(running==0) {
       running=1;
       new_poem();
       copy_to_old();
       new_poem();
       call_out("do_test",2);
     }
}

void do_init(object me)
{ 
    tell_object(me,"\n̽�������㣺�������answer <...>����ʫ�䣬author <...>���ش�����������\n\n");
    return;
}

int do_author(string arg)
{   object me=this_player();
    
    if(!arg) return notify_fail("������˭��\n");

    if( living(me) ) me->receive_damage("sen",5+random(15));

    arg=replace_string(arg," ","");
    if(me->query_temp("poem/index")!=poem_index ) 
      return notify_fail("ֻ�жԳ�ʫ�����ܻش�������˭��\n");

    if(answerd==1) return
      notify_fail("�����Ѿ��ش������ʫ�������ˡ�\n");
      
    message_vision("$N˵��������ʫ��������"+arg+"��\n",me);
    if(arg==author) { 
         answerd=1;
         write("̽��˵�������ˣ�\n");
         poem_reward1(me);
    } else {
      me->add_temp("poem/wrong",1);
      if(me->query_temp("poem/wrong")>20) poem_penalty(me);
    }
    return 1;
}

int do_answer(string arg)
{ 
    object me=this_player();

    if(!arg) return notify_fail("�ش�ʲô��\n");

    if( living(me) ) me->receive_damage("sen",5+random(15));

    arg=replace_string(arg," ","");
    switch(random(2)) {
     case 0: message_vision("$N˵�������ǣ�����"+arg+"��\n",me);
             break;
     case 1: message_vision("$N�����"+arg+"��\n",me);
             break;
    }
    if(arg==current&&strlen(current)>2) {
      if(ans_curr==1) {
       write("�����Ѿ��ش�����ʫ�ˡ�\n");
       return 1;
      }
      ans_curr=1;
      
      //change to a new poem once this one is answered.
      index=length-1;

      me->set_temp("poem/index",poem_index);
      poem_reward(me,current_all);
    } else if(arg==last&&strlen(last)>2) {
      if(ans_last==1) {
       write("�����Ѿ��ش�����ʫ�ˡ�\n");
       return 1;
      }
      ans_last=1;
      poem_reward(me,last_all);
    } else {
      write("̽��ҡ��ҡͷ�����󲻶԰ɣ�\n");
      me->add_temp("poem/wrong",1);
      if(me->query_temp("poem/wrong")>20) poem_penalty(me);
    }

    return 1;
}

void poem_penalty(object me)
{
    message_vision("��Ȼһ������𣬰�$N������Ӱ�����ˣ�����\n",me);
    if(!me->query("dream_place")) me->move("/d/city/kezhan");
    else me->move((string)me->query("dream_place"));
    write("��������������֪�������Ͽ�һ�Σ�����������Щͷʹ������\n");
    me->set("sen",-1);
    me->set_temp("poem/wrong",0);

    return;
}

void poem_reward(object me,string arg)
{
    me->set_temp("poem/wrong",0);
    message_vision("̽����ͷ������"+arg+"����ʫ����ʫ��\n",me);
    poem_reward1(me);
}

void poem_reward1(object me)
{  
	int dx,pot,lite;
    switch(random(3)) {
     case 0: dx=3+random(6);
             me->add("daoxing",dx);
	     message_vision("$N�ĵ��������ˣ�\n",me);
	     break;
     case 1: pot=2+random(3);
	     if(me->query("potential")+pot-me->query("learned_points")<=100)
               me->add("potential",pot);
             message_vision("$N��Ǳ�������ˣ�\n",me);
	     break;
     case 2: lite=3+random(6);
             me->improve_skill("literate",lite);
	     message_vision("$N�Ķ���ʶ�ֽ����ˣ�\n",me);
	     break;
    }
    me->add("poem_answered",1);
    dx=me->query("poem_answered");
    if((dx-dx/10*10)==0) {
      message_vision("$Nٿ�ػ�Ϊһ�����̣��漴Ʈɢ�����ˣ�����\n",me);
      if(!me->query("dream_place")) me->move("/d/city/kezhan");
      else me->move((string)me->query("dream_place"));
      if(me->query("startroom")==this_place)
        me->set("startroom","/d/city/kezhan");
      me->save();
      message_vision("$Nһ���������������ۣ����������ƺ���������Ŀ������\n",me);
    }
}

void do_test()
{  
   int newt;
   string first,second,quest;

   if(strlen(current)>2&&ans_curr==0) {
     last=current;
     last_all=current_all;
     ans_last=0;
   }
   
   newt=0;
   while(newt==0) {
    if(!find_newline()) {
     copy_to_old();
     new_poem();
    } else {
      if(sscanf(poem[index],"%s  %s",first,second)==2 &&
       !sscanf(poem[index],"%*s��") && 
       !sscanf(poem[index],"%*s��") &&
       !sscanf(poem[index],"%*s��") ) {
         if(strlen(first)>2&&strlen(second)>2) {
	   newt=1;
         } 
      }
    }
   }

   first=replace_string(first," ","");
   second=replace_string(second," ","");
   current_all=first+"  "+second;
   ans_curr=0;
   if(random(2)==0) {
     quest=enscript(first);
     current=second;
     curr_show=quest+enscript("������");
     switch(random(2)) {
       case 0: 
         tell_room(this_object(),"̽��������"+quest+"���ĺ�����ʲô��\n");
         break;
       case 1:
         tell_room(this_object(),"̽��˵��"+quest+"������������ʲô���ţ�\n");
         break;
     }
   } else {
     quest=enscript(second);
     current=first;
     curr_show=enscript("������")+quest;
     switch(random(2)) {
       case 0:
         tell_room(this_object(),"̽���ʵ�����"+quest+"����ǰ�����ʲô��\n");
	 break;
       case 1:
         tell_room(this_object(),"̽���������������"+quest+"��ǰ����ʲô���ţ�\n");
	 break;
     }
   }

   if(sizeof(filter_array(all_inventory(this_object()), (:userp:))))
       call_out("do_test",60);
   else
       running=0;
   return;
}

int do_look(string arg)
{   int i;

    if(!arg || arg!="poem") return 0;

    write("\n\n    "+author1+"��"+title1+"\n");
    for (i=0;i<length1;i++) {
      write("    "+poem1[i]+"\n");
    }
    write("\n\n\n");

    write(enscript("��ǰ��Ŀ��������")+curr_show+"\n\n");

    return 1;

}

void copy_to_old()
{    int i;
     author1=author;
     title1=title;
     length1=length;
     poem1=({});
     last="";
     for (i=0;i<length;i++)
       poem1+=({poem[i]});
     return;
}

void new_poem()
{   string filename,buf;
    int i,j,k;

    length=0;
    while (length==0) {
    while((k=(1+random(POEMS)))==poem_index);
    filename=__DIR__"poem/poem"+k;
    buf=read_file(filename,1,1);
    sscanf(buf,"%s��%s",author,title);
    i=0;
    j=0;
    poem=({});
    while(buf=read_file(filename,2+i,1)) {
      if(strlen(buf)>2) {
        buf=replace_string(buf,"\n","");
        poem+=({buf});
	j++;
      }
      i++;
    }
    length=j;
    }
    poem_index=k;
    answerd=0;
    index=-1;
    chance=3*100/(1+length);
    if(length<3) {
      chance=100;
    }
    return;
}

int find_newline()
{
   index++;
   while(index<length) {
     if(random(100)<chance) {
       return 1;
     } else index++;
   }
   return 0;
}

string enscript(string arg)
{    string result;
     string *color=({BLK,RED,GRN,YEL,BLU,MAG,CYN,WHT,
                     HIR,HIG,HIY,HIB,HBRED,HBGRN,HBYEL,
		     HBBLU,HBMAG,BBLK,BRED,BGRN});
     int len,i;

     len=sizeof(color);
     result="";
     i=sizeof(arg);
     while(i>2) {
       if(random(2)==0) {
         result=color[random(len)]+NOR+arg[i-2..i-1]+result;
       } else {
         result=arg[i-2..i-1]+result;
       }
       i-=2;
     }
     result=NOR+arg[0..1]+result;

     return result;
}

