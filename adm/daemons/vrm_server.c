// /adm/daemons/vrm_server.c

/************************************************
 * vrm_server.c                                 *
 * ���������Թ������� (Virtual Random Maze)   *
 *                                              *
 * by Find.                                     *
 *              ������Ϸ ���� MUD.              *
 ************************************************/

/******************************************************
 * �Թ���һ����Ϸ�ﾭ��Ҫ�õ��Ķ�������ǰ���Թ�����Ҫ *
 * ��ʦһ������һ��������ֹ����ƣ���ʱ����������һ�� *
 * ������ҳ���ȷ����·���Թ���ֱ�й©���Թ��Ͳ����� *
 * Ϊ�Թ��ˣ�������ʦ�Ƕ��ʾ���֭���Թ���Ƶľ�������,*
 * ���ٸ��ӵ��Թ�����Ҳ�ᱻ�ҵ���ȷ��·�ߣ����ҹ��ڸ� *
 * �����ߵ��Թ�Ҳʹ��Ҹо����ڷ�����������Ȥ����˲� *
 * �����뷨��                                         *
 * ����Թ��Ĳ����㷨�����򵥣��Թ��Ĵ��澡����ʡ���� *
 * �壬�Թ������������������������Թ�����ֻ���� *
 * ����ߵ�ʱ�Ż�װ���ڴ棬�����Թ�����Ҳ����ͨ��ROOM *
 * һ����һ��ʱ��û�б��ο����������ٽ�ʡ�����壬���� *
 * ���Թ�һ��ʱ��û�б��ο������Ա���ȫ�ݻ٣��´����� *
 * Ҫ��ʱ������½������ֻ����һ���µ��Թ���������ʦ *
 * д������Թ�ֻ��涨һЩԤ��Ĳ������Թ��ĵ��߳��� *
 * �����������������������ʮ��������ǧ�����䡢·��ʱ *
 * ʱ��ͬ������Թ��ͽ������ˣ�������������д��Ч�� *
 * ����Ϸ�Ŀ����ԡ�                                   *
 * �����Ŀǰ�ʺ���������Թ��������Թ��ڷ���������� *
 * ����ͬ������һƬ���֡�һƬ�صصȣ���Ҫ����������� *
 * �������������һ������ڡ�һ����ֵ���������Ҫ *
 * �����Լ�������涨���Թ��ڷ���������һЩ����ʹ�� *
 * �ڷ���������仯�������������������Э�������Ը *
 * ����ʦ����ֻ�����Թ�������Ӳ��֣����ü����Թ���� *
 * ��һ����ȫ��������򣬹������Ժ�����ʦ�����ɶ��ˡ� *
 * Ŀǰ����Ϸʹ�õ��Թ�һ��Ϊ���߳�10��40������������ *
 * ����Թ���Ҳ��֪��������Դ���һ��˵����Ҫ�����Լ� *
 * �ķ���������������������������ͨ�Ļ�������һ����� *
 * Ϊ100x100���Թ�Ӧ��Ҳ��һ�����ɵ����顣            *
 * ���ڲ��� virtual object��ǣ�浽һ�㰲ȫ���⣬��Ҫ��*
 * ���Լ���ϵͳ����������                             *
 ******************************************************/

#pragma optimize

#define N		8
#define S		4
#define W		2
#define E		1
#define ALL		15

/****************************************************
 * �Թ��ĵ��߳����ֵĿǰ�ݶ�Ϊ 100����������Թ���
 * ����Ͳ����ȽϺķ���Դ���߳� 100 ���Թ�'���'����
 * 100x100 ���� 10000 �������һ���Թ���һ���������
 * ������һ���ʵʱ�Թ���ʵʱ�Թ���ָ����Ϸ���й���
 * ����ʱ�� destruct ������Ҫ�ֻ���ʱ���������Թ�����
 * ���߳��� 10 �� 50 ֮��Ϊ�ˡ����贴������Թ����м�
 * ������ʮ�����������Թ���Ӧ������������������Ϸ��
 * ��ʱ������Ϸ������һ��ʱ�䣨����20�룩��ֹ��ҵ��롣
 * ��Ϸͨ�������������������´��Թ���
 * ��֪˭���õ���ô����Թ�������������
 ****************************************************/
#define MAX_LONG	100

// ֻҪ�����������������ķ���Ϳ϶���һ�����.
// �����ܵĳ���������.
// define ����涨�������ֻ������������.
// Ҳ���Ƕ������������ڵķ��������ر�һ��.
// ����ʹ������ڿ����ĸ������г��ںܷ�
// ������Ϸ��Ȥ��
#define TWO_VALID_LEAVES

inherit F_CLEAN_UP;

class coordinate{ int x; int y; }
class coordinate *newpath = ({}),/*���������*/
	enter,/* ������� */
	leave;/* �������� */

private string *valid_dirs = ({ "south","north","west","east" });
private mapping reverse_dir = ([
"north" : "south",
"south" : "north",
"west"  : "east",
"east"  : "west",
]);

// ȫ�Թ���������.
private mixed *all;

/***************** �Թ���һЩԤ�����ԣ�*****************/
private int l;				// �Թ��ĵ��߳�
private string *inherit_rooms = ({});	// �Թ�����̳еĵ�������
private string entry_dir;		// �Թ���ڷ���
private string link_entry_dir;		// �Թ��������������ӷ���
private string link_entry_room;		// �Թ�������������򵵰����ļ���
private string link_exit_dir;		// �Թ���������������ӷ���
private string link_exit_room;		// �Թ��������������򵵰����ļ���
private string entry_short;		// �Թ���ڵĶ�����
private string entry_desc;		// �Թ���ڵĳ�����
private string exit_short;		// �Թ����ڵĶ�����
private string exit_desc;		// �Թ����ڵĳ�����
private string *maze_room_desc	= ({});	// �Թ�����ĳ�����
private string maze_room_short;		// �Թ�����Ķ�����
private int is_outdoors = 0;		// �Թ������Ƿ�Ϊ����
private string *maze_npcs = ({});	// �Թ��еĹ���
/******************* ---- END ---- *********************/

// �������.
private int maze_built = 0;

// ����ȫ�����.
private void refresh_vars();

// �����Թ�
private void create_maze();

// ѡ���������.
private int random_out(int x,int y,int n);

// ��������.
private void link_to_north(int x,int y);
private void link_to_south(int x,int y);
private void link_to_west(int x,int y);
private void link_to_east(int x,int y);

// �����ѽ����Թ��ĵ�ͼ.
private void paint_vrm_map();

private string mroom_fname(int x,int y)
{ return sprintf("%s/%d/%d",base_name(this_object()),x,y);}


private void refresh_vars() // ����ȫ�����.
{
	newpath = ({});
	all = 0;
}

// ��һЩ��������ĺϷ��Լ��
private int check_vars()
{
	int i,n;

	if( (l < 5) || l > MAX_LONG )
		return 0;

	inherit_rooms -=({0});
	if( !n = sizeof(inherit_rooms) )
		return 0;

	for(i=0;i<n;i++)
		if(!stringp(inherit_rooms[i]) || (inherit_rooms[i] == ""))
			return 0;

	if(!stringp(entry_dir) || (member_array(entry_dir,valid_dirs) == -1) )
		return 0;
/*
	if(!stringp(link_entry_dir) || (member_array(link_entry_dir,valid_dirs) == -1) )
		return 0;

	if(!stringp(link_exit_dir) || (member_array(link_exit_dir,valid_dirs) == -1) )
		return 0;
*/
	if(!stringp(link_entry_room) || (link_entry_room == ""))
		return 0;

	if(!stringp(link_exit_room) || (link_exit_room == ""))
		return 0;

	if(!stringp(entry_short) || (entry_short == ""))
		return 0;

	if(!stringp(exit_short) || (exit_short == ""))
		return 0;

	if(!stringp(entry_desc) || (entry_desc == ""))
		return 0;

	if(!stringp(exit_desc) || (exit_desc == ""))
		return 0;

	maze_room_desc -=({0});
	if( !n = sizeof(maze_room_desc) )
		return 0;

	for(i=0;i<n;i++)
		if(!stringp(maze_room_desc[i]) || (maze_room_desc[i] == ""))
			return 0;

	if(!stringp(maze_room_short) || (maze_room_short == ""))
		return 0;

	return 1;
}

private int random_out(int x,int y,int n) // ѡ��������ں���.
{
	int *outs = ({}), retn = 0;
	class coordinate temp;

	// The west room is (x-1,y)
	if( n&W
	&& ((x-1) >= 0)
	&& !all[x-1][y] )
	{
		temp = new(class coordinate);
		temp->x = x-1;
		temp->y = y;

		// ����ķ��䲻�ڴ������б� newpath ��.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ W });
	}

	// The east room is (x+1,y)
	if( n&E
	&& ((x+1) < l)
	&& !all[x+1][y] )
	{
		temp = new(class coordinate);
		temp->x = x+1;
		temp->y = y;

		// ����ķ��䲻�ڴ������б� newpath ��.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ E });
	}

	// The south room is (x,y-1)
	if( n&S
	&& ((y-1) >= 0)
	&& !all[x][y-1] )
	{
		temp = new(class coordinate);
		temp->x = x;
		temp->y = y-1;

		// ����ķ��䲻�ڴ������б� newpath ��.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ S });
	}

	// The north room is (x,y+1)
	if( n&N
	&& ((y+1) < l)
	&& !all[x][y+1] )
	{
		temp = new(class coordinate);
		temp->x = x;
		temp->y = y+1;

		// ����ķ��䲻�ڴ������б� newpath ��.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ N });
	}

#ifdef TWO_VALID_LEAVES
	// �������������,����ر�һ��.
	if(sizeof(outs) >= 3)
		outs -= ({ outs[random(sizeof(outs))] });
#endif

	for(int i=0;i<sizeof(outs);i++)
		retn |= outs[i];

	return retn;
}

private void create_maze()
{
	int i;
	class coordinate *valid_leaves=({}),temp;

	refresh_vars(); // ����ȫ�����.
	if( !check_vars() )   // ��һЩԤ��������м�顣
		return;

	// 1.ȷ���Թ����߳�.
	all = allocate(l);
	for(i=0;i<l;i++)
		all[i] = allocate(l);	// ��������.

	enter = new(class coordinate);

	switch (entry_dir)
	{
		case "south":
			// enter �������.
			enter->x = to_int(l/2); // ȡ���Թ��Ƚ�ƽ�⡣
			enter->y = 0;
			all[enter->x][enter->y] |= S;
			break;
		case "north":
			enter->x = to_int(l/2);
			enter->y = l-1;
			all[enter->x][enter->y] |= N;
			break;
		case "west":
			enter->y = to_int(l/2);
			enter->x = 0;
			all[enter->x][enter->y] |= W;
			break;
		case "east":
			enter->y = to_int(l/2);
			enter->x = l-1;
			all[enter->x][enter->y] |= E;
			break;
	}

	// ������������.
	newpath += ({ enter });

	// ������ѭ��.
	do
	{
		int x,y,out,numb;

		// ����һЩ������ʼ��.
		if( !(numb=sizeof(newpath)) )
			continue;
		numb = random(numb);
		reset_eval_cost();
		x = newpath[numb]->x;
		y = newpath[numb]->y;

		// ������������ܵĳ�������ر�һ������:
		out = ALL^(all[x][y]);
		out = random_out(x,y,out);

		if(!out) // û�п��ܵĳ�����.
		{
			newpath -= ({ newpath[numb] });
			continue;
		}

		// ��������.
		if(out&W) link_to_west(x,y);
		if(out&E) link_to_east(x,y);
		if(out&N) link_to_north(x,y);
		if(out&S) link_to_south(x,y);

		// ��ǰ���䴦�����.
		newpath -= ({ newpath[numb] });
	}
	while (sizeof(newpath));

	switch (entry_dir)
	{
		case "west":
			for(i=0;i<l;i++)
				if(all[l-1][i])
				{
					temp = new(class coordinate);
					temp->x = l-1;
					temp->y = i;
					valid_leaves += ({temp});
				}
			break;
		case "east":
			for(i=0;i<l;i++)
				if(all[0][i])
				{
					temp = new(class coordinate);
					temp->x = 0;
					temp->y = i;
					valid_leaves += ({temp});
				}
			break;
		case "south":
			for(i=0;i<l;i++)
				if(all[i][l-1])
				{
					temp = new(class coordinate);
					temp->x = i;
					temp->y = l-1;
					valid_leaves += ({temp});
				}
			break;
		case "north":
			for(i=0;i<l;i++)
				if(all[i][0])
				{
					temp = new(class coordinate);
					temp->x = i;
					temp->y = 0;
					valid_leaves += ({temp});
				}
			break;
	}

	if( !(i=sizeof(valid_leaves)) ) // û�г��� �����½���
	{
		call_other(this_object(),"create_maze");
		return;
	}

	if(i == 1)
		leave = valid_leaves[0];
	else
		leave = valid_leaves[random(i)]; // ���ѡһ��.

	switch (entry_dir)
	{
		case "south":
			all[leave->x][leave->y] |= N;
			break;
		case "north":
			all[leave->x][leave->y] |= S;
			break;
		case "west":
			all[leave->x][leave->y] |= E;
			break;
		case "east":
			all[leave->x][leave->y] |= W;
			break;
	}

	// �Թ�������ϡ�
	maze_built = 1;

	// ������ɵ��Թ���ͼ��
	// ��ͼ�ļ�ΪͬĿ¼��ͬ����'.map' �ļ���
	// ���Ƶ�ͼҲ�������������ʦ�Ĺ�����
	// ����Ҫ�ɿ���������ڱ�Ŀ¼��'д'��
	//paint_vrm_map();
}

private void link_to_west(int x,int y)	// The west room is (x-1,y)
{
	class coordinate temp;
	// can't link. ��ǰ�����Ѿ���������ķ�����.
	if( (x-1) < 0 )
		return;

	temp = new(class coordinate);
	temp->x = x-1;
	temp->y = y;

	// ����ķ����Ѿ��� path ��,���� ���ڴ������б� newpath ��.
	if(all[temp->x][temp->y] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y] |= W;
	all[temp->x][temp->y] |= E;
	newpath += ({temp});
}

private void link_to_east(int x,int y)	// The east room is (x+1,y)
{
	class coordinate temp;
	// can't link. ��ǰ�����Ѿ������ķ�����.
	if( (x+1) >= l )
		return;

	temp = new(class coordinate);
	temp->x = x+1;
	temp->y = y;

	// ����ķ����Ѿ��� path ��,���� ���ڴ������б� newpath ��.
	if(all[temp->x][temp->y] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y] |= E;
	all[temp->x][temp->y] |= W;
	newpath += ({temp});
}

private void link_to_south(int x,int y)	// The south room is (x,y-1)
{
	class coordinate temp;
	// can't link. ��ǰ�����Ѿ������϶˵ķ�����.
	if( (y-1) <0 )
		return;

	temp = new(class coordinate);
	temp->x = x;
	temp->y = y-1;

	// �϶˵ķ����Ѿ��� path ��,���� ���ڴ������б� newpath ��.
	if(all[temp->x][temp->y] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y] |= S;
	all[temp->x][temp->y] |= N;
	newpath += ({temp});
}

private void link_to_north(int x,int y)	// The north room is (x,y+1)
{
	class coordinate temp;
	// can't link. ��ǰ�����Ѿ�����˵ķ�����.
	if( (y+1) >= l )
		return;

	temp = new(class coordinate);
	temp->x = x;
	temp->y = y+1;

	// ���˵ķ����Ѿ��� path ��,���� ���ڴ������б� newpath ��.
	if(all[temp->x][temp->y] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y] |= N;
	all[temp->x][temp->y] |= S;
	newpath += ({temp});
}

// �����ѽ����Թ��ĵ�ͼ.
private void paint_vrm_map()
{
	string hor = "��" ,ver = "��  ",room = "��",sroom = "��";
	int x,y;
	string output = "",map_file;

	for(y=(l-1);y>=0;y--)
	{
		reset_eval_cost();

		output += sprintf("y=%-3d: ",y);
		for(x=0;x<l;x++)
		{
			output += sprintf("%s",
				(( (x==enter->x) && (y==enter->y))
				|| ( (x==leave->x) && (y==leave->y) ))?
				sroom:room);

			if( (all[x][y])&E ) // have east
				output += hor;
			else
				output += "  ";
		}

		output += "\n";
		output += "       ";
		for(x=0;x<l;x++)
		{
			if( (all[x][y])&S ) // have south
				output += ver;
			else
			output += "    ";
		}
		output += "\n";
	}

	map_file = sprintf( "%s.map",base_name(this_object()) );
	write_file(map_file,output,1);
}

nomask int clean_up()
{
	string fname;
	int x,y;
	object *maze_objs = ({}),link_room;

	if(!maze_built)
	{
		destruct(this_object());
		return 0;
	}

	fname = base_name(this_object());

	if( objectp(link_room = find_object(sprintf("%s/entry",fname))) )
	{
		link_room->clean_up();
		if( objectp(link_room) )
			return 1;
	}

	if( objectp(link_room = find_object(sprintf("%s/exit",fname))) )
	{
		link_room->clean_up();
		if( objectp(link_room) )
			return 1;
	}

	for(x=0;x<l;x++)
		for(y=0;y<l;y++)
			if(objectp(find_object(sprintf("%s/%d/%d",fname,x,y))))
				maze_objs += ({find_object(sprintf("%s/%d/%d",fname,x,y))});

	maze_objs->clean_up();
	maze_objs -= ({0});

	if(sizeof(maze_objs))
		return 1;
	else
	{
		destruct(this_object());
		return 0;
	}
}

// ��ʦ���� update �����Թ������ǿ�Ƹ����Թ���
// ����ʱ�Թ��е���Ҿ�Ҫȥ VOID �ˡ�
void remove(string euid)
{
	string fname = base_name(this_object());
	object m_room;
	int x,y;

	for(x=0;x<l;x++)
		for(y=0;y<l;y++)
			if(objectp(m_room = find_object(sprintf("%s/%d/%d",fname,x,y))))
				destruct(m_room);
	if(find_object(sprintf("%s/entry",fname)))
		destruct(sprintf("%s/entry",fname));
	if(find_object(sprintf("%s/exit",fname)))
		destruct(sprintf("%s/exit",fname));
}

/**** ������Ԥ���Թ������Ľӿں��� ****/
// �Թ��ĵ��߳�
void set_maze_long(int mlong)
{
	if(!intp(mlong))
		return;

	// ��СΪ 5����С��ûʲô���塣
	if( (mlong < 5) || mlong > MAX_LONG )
		return;

	l = mlong;
}

// �Թ��������̳е�����ĵ������ơ�
void set_inherit_room( mixed rooms )
{
	if(stringp(rooms))
	{
		// �˵����Ƿ����
		if(file_size(sprintf("%s.c",rooms)) > 0)
			inherit_rooms = ({ rooms });
		return;
	}

	else if(arrayp(rooms))
	{
		foreach(string f in rooms)
		{
			if(!stringp(f) || f == "")
				return;
			if(file_size(sprintf("%s.c",f)) <= 0)
				return;
		}
		inherit_rooms = rooms;
		return;
	}

	return;
}

// ��ڷ���(�����ڶ���)
void set_entry_dir(string dir)
{
	if(!stringp(dir))
		return;

	// ��ڷ���ĺϷ��Լ��.
	if(member_array(dir,valid_dirs) == -1)
		return;

	entry_dir = dir;
}

//�������������ӷ���
void set_link_entry_dir(string dir)
{
	if(!stringp(dir) || dir == "")
		return;

	link_entry_dir = dir;
}

// �Թ�������������򵵰����ļ���
void set_link_entry_room(string lroom)
{
	if(!stringp(lroom) || lroom == "")
		return;

	if(file_size(sprintf("%s.c",lroom)) <= 0)
		return;

	link_entry_room = lroom;
}

//��������������ӷ���
void set_link_exit_dir(string dir)
{
	if(!stringp(dir) || dir == "")
		return;

	link_exit_dir = dir;
}

// �Թ��������������򵵰����ļ���
void set_link_exit_room(string lroom)
{
	if(!stringp(lroom) || lroom == "")
		return;

	if(file_size(sprintf("%s.c",lroom)) <= 0)
		return;

	link_exit_room = lroom;
}

// �Թ���ڵĶ�����
void set_entry_short(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	entry_short = desc;
}

// �Թ���ڵĳ�����
void set_entry_desc(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	entry_desc = desc;
}

// �Թ����ڵĶ�����
void set_exit_short(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	exit_short = desc;
}

// �Թ����ڵĳ�����
void set_exit_desc(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	exit_desc = desc;
}

//�Թ�����Ķ�����
void set_maze_room_short(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	maze_room_short = desc;
}

//�Թ����������������ж�������������ÿ����
//���ʱ���������ѡ��һ����
void set_maze_room_desc(mixed desces)
{
	if(stringp(desces))
	{
		maze_room_desc = ({ desces });
		return;
	}

	if(arrayp(desces))
	{
		foreach(string desc in desces)
			if(!stringp(desc))
				return;
		maze_room_desc = desces;
		return;
	}
}

// �Թ������Ƿ�Ϊ���ⷿ��
void set_outdoors(int outd)
{
	if(!intp(outd))
		return;

	if(outd)
		is_outdoors = 1;
}

// �Թ��еĹ���
void set_maze_npcs(mixed npc)
{
	if(stringp(npc))
	{
		// �˵����Ƿ����
		if(file_size(sprintf("%s.c",npc)) > 0)
			maze_npcs = ({ npc });
		return;
	}

	else if(arrayp(npc))
	{
		foreach(string f in npc)
		{
			if(!stringp(f) || f == "")
				return;
			if(file_size(sprintf("%s.c",f)) <= 0)
				return;
		}
		maze_npcs = npc;
		return;
	}

	return;

}

/**** ������Ԥ���Թ������Ľӿں��� ****/

// �����Թ����䣬�� VIRTUAL_D ���á�
nomask object query_maze_room(string str)
{
	int random_rate = 20;	// �����ڷ��� npc �Ŀ�����
	int idx,x,y,exits;
	object ob;
	string f;

	if( previous_object() && (geteuid(previous_object()) != ROOT_UID) )
		return 0;

	if(!stringp(str) || str == "")
		return 0;

	if(!maze_built)	// �Թ�δ����
		create_maze();
	if(!maze_built)
		return 0;

	if(str == "entry")	// �Թ���ڷ���
	{
		f = inherit_rooms[random(sizeof(inherit_rooms))];

		ob = new(f);
		if(!ob)
			return 0;
		ob->set("virtual_room",1);
		ob->set("short",entry_short);
		ob->set("long",entry_desc);
		if(is_outdoors)
			ob->set("outdoors",1);
		ob->set(sprintf("exits/%s",link_entry_dir),link_entry_room);
		ob->set(sprintf("exits/%s",reverse_dir[entry_dir]),mroom_fname(enter->x,enter->y));
		if( sizeof(maze_npcs) && (random(100) <= random_rate) )
		{
			ob->set("objects",([
	maze_npcs[random(sizeof(maze_npcs))] : 1,
]));
			ob->setup();
		}
		return ob;
	}

	if(str == "exit")	// �Թ����ڷ���
	{
		f = inherit_rooms[random(sizeof(inherit_rooms))];

		ob = new(f);
		if(!ob)
			return 0;

		ob->set("virtual_room",1);
		ob->set("short",exit_short);
		ob->set("long",exit_desc);
		if(is_outdoors)
			ob->set("outdoors",1);
		ob->set(sprintf("exits/%s",link_exit_dir),link_exit_room);
		ob->set(sprintf("exits/%s",entry_dir),
			mroom_fname(leave->x,leave->y));
		if( sizeof(maze_npcs) && (random(100) <= random_rate) )
		{
			ob->set("objects",([
	maze_npcs[random(sizeof(maze_npcs))] : 1,
]));
			ob->setup();
		}
		return ob;
	}

	idx = member_array('/', str);
	if( idx == -1 )
		return 0;

	if(!sscanf(str[0..idx-1],"%d",x))
		return 0;
	if(!sscanf(str[idx+1..],"%d",y))
		return 0;

	if( !exits = all[x][y] )
		return 0;

	f = inherit_rooms[random(sizeof(inherit_rooms))];
	ob = new(f);
	if(!ob)
		return 0;

	ob->set("virtual_room",1);
	ob->set("short",maze_room_short);
	ob->set("long",maze_room_desc[random(sizeof(maze_room_desc))]);
	if(is_outdoors)
		ob->set("outdoors",1);

	if(exits&W)
		ob->set("exits/west",mroom_fname(x-1,y));
	if(exits&E)
		ob->set("exits/east",mroom_fname(x+1,y));
	if(exits&N)
		ob->set("exits/north",mroom_fname(x,y+1));
	if(exits&S)
		ob->set("exits/south",mroom_fname(x,y-1));

	if( (x == enter->x) && (y == enter->y) )
		ob->set(sprintf("exits/%s",entry_dir),
			sprintf("%s/entry",base_name(this_object())));
	if( (x == leave->x) && (y == leave->y) )
		ob->set(sprintf("exits/%s",reverse_dir[entry_dir]),
			sprintf("%s/exit",base_name(this_object())));

	if( sizeof(maze_npcs) && (random(100) <= random_rate) )
	{
		ob->set("objects",([
	maze_npcs[random(sizeof(maze_npcs))] : 1,
]));
		ob->setup();
	}

	return ob;
}