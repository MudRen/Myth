// Room: /changan/phomes
//cglaem...12/31/96.
//mon. 2/23/97.

inherit ROOM;

void create ()
{
  set ("short", "סլ��");
  set ("long", @LONG

��ˮ֮����һ��סլ�����غ�������һ����Ư����С������
�������컣���Ϣ���£�����ס�ҵľ������ڡ�����С¥
ǰ��������(paizi)��д��Щ�˼ҵ����֡�

LONG);
  set("exits", ([ /* sizeof() == 3 */
  "south" :__DIR__"wside5",
]));

  setup();
}

void init()
{
        add_action("show_name", "look");
	add_action("enter_home","",1);
}

int show_name(string arg)
{     
      mixed *files; 
      string who,result,content,chinese;
      int n,i,j,k;

      if(!arg||arg!="paizi") return 0;
      files=get_dir("/d/changan/playerhomes/");
      n=sizeof(files);
      j=0;
      for(i=0;i<=n-1;i++) {
	if(sscanf(files[i], "h_%s.c", who)==1) {
	  files[j]=who;
	  ++j;
        }
      }
      result="";
      if (j>0) {
	--j;
	k=0;
	for (i=0;i<=j;i++) {
	  content=read_file("/data/user/"+files[i][0..0]+
	    "/"+files[i]+".o");
          if(content){
            if(sscanf(content,"%*s\"name\":\"%s\"",
	      chinese)==2) {
	      result+=sprintf("  %-10s��%-16s  ",files[i],chinese);
	      if(k==1) result+="\n";
	      k=1-k;
            }
          }
        }
      }
      write("\n                        ���֮�� \n");
      write("\n"+result+"\n");
      
      return 1;
}

int enter_home(string arg)
{     
      string name,*files;
      object me=this_player();

      name=query_verb();
      files=get_dir("/d/changan/playerhomes/");
      if(member_array("h_"+name+".c",files)>-1) {
	message_vision("$N�����һ���ţ����˽�ȥ��\n",me);
        me->move("/d/changan/playerhomes/h_"+name);
	return 1;
      }
      else return 0;
	
}

