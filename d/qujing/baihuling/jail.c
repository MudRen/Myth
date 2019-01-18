// mon@xyj 10/10/98

inherit ROOM;

int max_i = 2;
int max_j = 3;
int max_k = 2;
string maze_file=__DIR__"maze_generator";

object maze_g=0;
mixed rooms;

void dest();

void create()
{
  set ("short", "����");
  set ("long", @LONG

�����ǿݹǶ��Ĵ����ң�����ץ�����˶��ȷ������������
����ʱ��ѡ�á���ע�⵽����ʯ���ƺ���Щ�ɶ�������һ
�ᣬ�����ֳ�һ�����ڣ�Ҳ��������ȥ��(zuan)

LONG);

//  set("objects", ([
//	__DIR__"maze_generator":1,
//     ]));

  set("no_move",1);
  set("no_fight",1);
  set("no_magic",1);
  set("valid_startroom",1);

  setup();
}

void init ()
{
    object me=this_player();
    
    me->set_temp("startroom",query("startroom"));
    me->set("startroom",__DIR__"jail");
    me->save();

    add_action ("do_test","zuan");
    add_action ("do_void","cast");
    add_action ("do_void","exert");
//    if (! maze_g)
//      maze_g = present ("maze generator", this_object());
}
int do_void(string arg)
{
    return 1;
}
void setup_rooms()
{
    dest();
//    if (! maze_g)
//      maze_g = present ("maze generator", this_object());
    maze_g=load_object(maze_file);
    maze_g->do_setup(""+max_i+" "+max_j+" "+max_k);
    rooms=maze_g->generate_room(__DIR__"small_cave");
}

int do_test (string arg)
{
    object room;
    int i,j,k;
    
    if(!rooms)
	setup_rooms();
    else {
        for(i=0;i<max_i;i++)
	  for(j=0;j<max_j;j++)
	    for(k=0;k<max_k;k++) {
		if(!rooms[i][j][k]) {
		    setup_rooms();
		    break;
		}
	    }
    }

    message_vision("$N������ŵ����һ��С���������ˣ�����\n",this_player());
    this_player()->move(rooms[0][0][0],1);
    tell_object(this_player(),"�����һ�������ص�ˤ����ȥ��\n");
    message_vision("\n$N���һ�������������\n",this_player());
//    maze_g->do_show("1");
//    maze_g->do_show("2");
    rooms[random(max_i)][1+random(max_j-1)][random(max_k)]
	->set("exits/out",__DIR__"small_exit");
    return 1;
}

// mon
void dest()
{
    object* child=children(__DIR__"small_cave");
    int i=sizeof(child);
    
    while(i--) 
	if(clonep(child[i]))
	    destruct(child[i]);
}

int clean_up ()
{
      return 0;
}

