//Cracked by Roath
// bbsboard.c

#include <ansi.h>

#define BOARD_CAPACITY query("capacity")

inherit ITEM;
inherit F_SAVE;

int do_readgroup(string msg);
void do_readnewsgroup(object ob, int idx);
void do_readarticle(object ob, int idx, int sidx);
void do_startmore(string cmd, string *text, int line, object ob, int idx, int sidx);

void setup()
{
	string loc;

	if( stringp(loc = query("location")) )
		move(loc);
	set("no_get", 1);
	restore();
}

void init()
{
    mapping *news;
    int    i, j;
    
	add_action("do_makegroup", "mkgroup");
	add_action("do_rmgroup", "rmgroup");
	add_action("do_readgroup", "read");
	add_action("do_cpbboard", "cpbboard");

	news = query("news");	
	if( !pointerp(news) || !sizeof(news) )
	   return;
	   
	for(i=0; i<sizeof(news); i++)  {
	   news[i]["used"] = 0;
	   for(j=0; j<sizeof(news[i]["index"]); j++) {
	      news[i]["index"][j]["used"] = 0;
	   }
	}
	
    set("news", news);
    save();
    
   	return;	
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("board_id")) ) return 0;
	return DATA_DIR + "board/" + id;
}

string short()
{
	mapping *news;

	news = query("news");
	if( !pointerp(news) || !sizeof(news) )
		return ::short() + " [ Ŀǰû���κ������� ]";
		
	return sprintf("%s [ Ŀǰ���� %d �������� ]", ::short(), sizeof(news));	
}

string long()
{
	mapping *news;
	int i;
	string msg;

	news = query("news");
	msg = query("long");
	msg = msg + "���������飬���� read board��
========================================================================\n";
	if( !pointerp(news) || !sizeof(news) ) return query("long");

	for(i=0; i<sizeof(news); i++)   {
		msg += sprintf("[%2d]    %3d      %-30s   %12s\n",
			i+1, sizeof(news[i]["index"]), news[i]["name"], news[i]["id"]);
    }			
	return msg;
}

void done_postnews(object ob, int idx, int sidx, mapping note, string text)
{
     mapping *news;
     int  last;
      
     note["msg"] = text;
     news = query("news");
     news[idx]["time"] = time();
     if( !sizeof(news[idx]["index"]) )
         news[idx]["index"] = ({ });
         
     news[idx]["index"] += ({ note });    
     note["time"] = time();
      
     if(sidx != -1)  {
        last = sidx;
        while(1)  {
           news[idx]["index"][last]["used"] -= 1;
           if(!news[idx]["index"][last]["next"])  break;
           last += news[idx]["index"][last]["next"];
        }
        news[idx]["index"][last]["next"] = 
           (sizeof(news[idx]["index"]) - last -1);
     }
     
     if( sizeof(news[idx]["index"]) > 100 )
         news[idx]["index"] = news[idx]["index"][50..100];

     set("news", news);
     tell_object(ob, "������ϡ�\n\n\n");
     
     save();
     
     //if(sidx == -1)
        do_readnewsgroup(ob, idx);
     /*else
        do_readarticle(ob, idx, sidx);   
     */   
}


void do_postnews(object ob, int idx, int sidx, string title)
{
    mapping note;
    
    note = allocate_mapping(7);
    note["title"] = title;
    if(sidx == -1)
       note["reply"] = "f";
    else
       note["reply"] = "t";
    note["next"] = 0;
    note["used"] = 0;
    note["author"] = ob->query("name") + "(" + capitalize(ob->query("id"))+")";
    ob->edit( (: done_postnews, ob, idx, sidx, note :) ); 
    return;
}


void inside_group(string line, object ob, int idx, int sidx)
{
    string cmds, title;
    int   cur, num;
    mapping  *news;
   
    news = query("news"); 
    if(line == "q" )  {
        cur =  sidx;
        while(1)   {
           news[idx]["index"][cur]["used"] -= 1;
           if(!news[idx]["index"][cur]["next"])
              break;
           cur += news[idx]["index"][cur]["next"];
        }
        do_readnewsgroup(ob, idx);
    }
/*
    else if(line[0..1] == "p ")  {
        sscanf(line, "%s %s", cmds, title);
        if(!title)
            write("������ָ��һ�����⡣\n");
        else   
            do_postnews(ob, idx, sidx,  title);
    }
*/
    else  {
	    write("\n(q �˳�)");
        input_to("inside_group", ob, idx, sidx);
    }    
}

void do_readarticle(object ob, int idx, int sidx)
{
    mapping *news;
    mapping last_read_time;
    string msg, myid;
    int   i, cur;
    
    myid = query("board_id");    
    last_read_time = ob->query("bbs_last_read/"+myid);
   
    news = query("news");
    // add group check here
    
    msg = "\n\n", cur = sidx;
    while( 1 ) {
       msg += sprintf("%s%s%s [%d] %-30s %s(%s)\n", HIC, 
       news[idx]["name"], NOR, cur+1, news[idx]["index"][cur]["title"],
       news[idx]["index"][cur]["author"], 
       ctime(news[idx]["index"][cur]["time"])[0..9]);
       msg += "-------------------------------------------------------------------\n";
       msg += news[idx]["index"][cur]["msg"];
       msg += "\n\n";

       news[idx]["index"][cur]["used"] += 1;
                
       if( !news[idx]["index"][cur]["next"] ) break;
       
       cur += news[idx]["index"][cur]["next"];  
    }
   
    if( !mapp(last_read_time) )   {
        ob->set("bbs_last_read/"+myid, 
          ([ news[idx]["id"]: news[idx]["index"][cur]["time"] ]) ); 
    }  
    else {
       if( undefinedp(last_read_time[news[idx]["id"]]) ||
         news[idx]["index"][cur]["time"] > last_read_time[news[idx]["id"]] )
            last_read_time[news[idx]["id"]] = news[idx]["index"][cur]["time"];
    }
    
    //write(msg); 
    do_startmore("", explode(msg, "\n"), 0, ob, idx, sidx);

    /*write("\n��������(q �˳� p ����)");
     input_to("inside_group", ob, idx, sidx); */
    return;
}


void  in_group(string line, object ob, int idx, int restricted)
{
    int i, num;
    mapping  *news, *nnews;
    string  cmds, title, msg;
    string  myid;
   
    news = query("news");
    
    if( line == "q")  {
       news[idx]["used"] -= 1;
       do_readgroup("board");
    }
    else if( line == "l" && !restricted )  {
       do_readnewsgroup(ob, idx);
    }
    else if( line[0..1] == "d " && !restricted )  {
       sscanf(line, "%s %d", cmds, num);
       if( num < 1 || num > sizeof(news[idx]["index"]) )  {
          write("û��������ԡ�\n");
       }
       else if( news[idx]["index"][num-1]["used"] > 0) {
          write("�������������ʹ�ã��㲻��ɾȥ��\n");
       }
       else {
          myid = ob->query("name")+"("+capitalize(ob->query("id"))+")";
          if(wizhood(ob) != "(admin)" && 
             myid != news[idx]["index"][num-1]["author"])  {
             write("�㲻��ɾȥ������ԣ���\n");
          }
          else {
             nnews = ({ });
             for(i=0; i<num-1;i++)  {
                if(news[idx]["index"][i]["next"] == num-1-i)  {
                   if(news[idx]["index"][num-1]["next"] == 0)
                      news[idx]["index"][i]["next"] = 0;
                   else   
                      news[idx]["index"][i]["next"] += 
                         (news[idx]["index"][num-1]["next"]-1);
                }
                else  if(news[idx]["index"][i]["next"] != 0 &&
                   news[idx]["index"][i]["next"] > num-1-i)
                   news[idx]["index"][i]["next"] -= 1;
                nnews += ({ news[idx]["index"][i] });
             }
             for(i=num; i<sizeof(news[idx]["index"]); i++)
                nnews += ({ news[idx]["index"][i] });
             
             news[idx]["index"] = nnews;
          
             msg = sprintf("ɾ���� %d ������....Ok��", num);  
             tell_object(ob, msg); 
             set("news", news);
             save();                                
          }
       }
       do_readnewsgroup(ob, idx);
    }
    else if( line[0..1] == "p " ) {
       sscanf(line, "%s %s", cmds, title);
       if(!title)  {
          write("������ָ��һ�����⡣\n");
          do_readnewsgroup(ob, idx);   
       }   
       else   
          do_postnews(ob, idx, -1,  title);
    }
    else { 
       sscanf(line, "%d", num);
       if( num < 1 || num > sizeof(news[idx]["index"]) )  {
          write("û��������ԡ�\n");
          do_readnewsgroup(ob, idx);
       }
       else {
          do_readarticle(ob, idx, num-1);
       }   
    } 
} 


void do_readnewsgroup(object ob, int idx)
{
    mapping *news, last_read_time;
    string myid;
    int   i, j, num, sum, cur;
    string msg, readflag;
    int   last_time, next;
   
    myid = query("board_id");
    last_read_time = ob->query("bbs_last_read/"+myid);
    news = query("news");
    
    if( !mapp(last_read_time) || undefinedp(last_read_time[news[idx]["id"]]) )
        last_time = 0;
    else
        last_time = last_read_time[news[idx]["id"]];
 

write("\n"+HIR+"************************************************************************"+NOR+"\n");
    write("��ӭ����"+HIC+news[idx]["name"]+NOR+"�����飡����\n");

write(HIR+"************************************************************************"+NOR+"\n");
    if(!sizeof(news[idx]["index"]))  {
       write("���������Ŀǰû���κ����ԡ�\n");
       write("��Ҫ������(p ����  q �˳�)");
       input_to("in_group", ob, idx, 1);
    }
    else {
       for(i=0; i<sizeof(news[idx]["index"]); i++)  {
          news[idx]["index"][i]["reply"] = "f";
       }
       for(i=0, j=0; i<sizeof(news[idx]["index"]); i++)  {
          if(news[idx]["index"][i]["reply"] == "f")  {
             sum = 1,   cur = i,   j++;
             readflag = " ";
             next = news[idx]["index"][cur]["next"];
             while( next != 0 )  {
                if(news[idx]["index"][cur+next]["time"] > last_time)
                   readflag = "N";
                news[idx]["index"][cur+next]["reply"] = "t";
                sum++;  cur += next;     //
                next = news[idx]["index"][cur]["next"];
             } 
             msg = sprintf("%2s [%2d] %32-s  %18s(%s)\n",
   ( news[idx]["index"][i]["time"] > last_time ? "N" : " "), i+1, 
news[idx]["index"][i]["title"],
                 news[idx]["index"][i]["author"],
                 ctime(news[idx]["index"][i]["time"])[0..9]);
             write(msg);       
          } 
       }
       write("\n");
       write("(q �˳� l ����  p ���� d ɾȥ �������): ");
       input_to("in_group", ob, idx, 0);
    }
}

int do_makegroup(string arg)
{
   int  num, i;
   mapping *news;
   mapping one_news;
   string name, id;
   
   if(wizhood(this_player()) != "(admin)")
      return notify_fail("��û�д����������Ȩ����\n");

   if( !arg ) return notify_fail("���� mkgroup ������������ ������Ӣ����\nȥ����һ���µ������顣\n");

   if(sscanf(arg, "%s %s", name, id) != 2)
	  return notify_fail("���� mkgroup ������������ ������Ӣ����\nȥ����һ���µ������顣\n");
	  
   news = query("news");
   if( !pointerp(news) || !sizeof(news) )
	  num = 0;
   else
	  num = sizeof(news);
	  
   if( num == BOARD_CAPACITY )
      return notify_fail("�Ѿ���̫��������飬������ rmgroup ɾȥһЩ�����õġ�\n");
  
   for(i=0; i<num; i++)   {
	  if(news[i]["id"] == id)
		 return notify_fail("���������Ѵ��ڡ�\n");
   }
		 
   one_news = allocate_mapping(6);
   one_news["id"] = id;
   one_news["name"] = name;
   one_news["index"] = ({ });
   one_news["time"] = time();
   one_news["used"] = 0;
   one_news["maker"] = this_player()->query("name");
   
   if(!num)
      news = ({ one_news });
   else
      news += ({ one_news });    
      
   set("news", news);
   tell_object(this_player(), "�����鴴���ɹ���\n");
   
   save();
   return 1; 
}
  

      
int do_rmgroup(string arg)
{
   int  num, i, delflag;
   mapping *news, *nnews;
   mapping one_news;
   string name, id;
   string msg;
   
   if(wizhood(this_player()) != "(admin)")
      return notify_fail("��û��ɾ�������Ȩ����\n");
      
   if(!arg)
	  return notify_fail("���� rmgroup ������Ӣ���� ȥɾһ�������顣\n");
	  
   news = query("news");
   if( !pointerp(news) || !sizeof(news) )
	  num = 0;
   else
	  num = sizeof(news);
 
   for(i=0; i<num; i++)   {
	  if(news[i]["id"] == arg)  {
         if( news[i]["used"] > 0 )  {
            msg = sprintf("%s%d%s", "Ŀǰ����", news[i]["used"], 
               "��ʹ��"+HIC+news[i]["name"]+NOR+"�����飬�����ؿ��ǣ�");
            write(msg);
            return 0;
	     }
	  }
   }
   	   
   nnews = ({ }); 
   delflag = 0;
   for(i=0; i<num; i++)   {
	  if(news[i]["id"] != arg)
	     nnews += ({ news[i] });
      else 
	     delflag = 1; 
   }
   if(delflag)	     
      tell_object(this_player(), "������ɾȥ�ɹ���\n");
   else
      tell_object(this_player(), "û����������飡\n");
     
   set("news", nnews);    
   save();         
   return 1;
}

void enter_group(string line)
{
    object me;
    int num;
    mapping *news;
   
    news = query("news");
    
    me = this_player(); 
    if( line == "q")  {
       write("�˳������顣\n");
       return;
    }
    else if( line == "l" ) {
       do_readgroup("board"); 
    }
    else  {
       sscanf(line, "%d", num);
       if( num < 1 || num > sizeof(news) )  {
           write("\nû����������顣\n");
           write("\n��ѡ��Ҫ�Ķ��������飺(q �˳� �������)");
           input_to("enter_group");
           return;
       }
       else {
          news[num-1]["used"] += 1; 
          do_readnewsgroup(me, num-1);
       }
    }
}

int do_readgroup(string arg)
{
    mapping *news, last_read_time;
    string myid;
    int   i, num, last_read;
    string msg;
   
    myid = query("board_id");    
    last_read_time = this_player()->query("bbs_last_read/"+myid);
    news = query("news");
    
    if( !pointerp(news) || !sizeof(news) )
       return notify_fail(HIG+" BBS " + NOR + "��û���κ������顣\n");
       
    if( !arg || arg != "board") return notify_fail("ָ���ʽ��read board\n");
   

write("\n"+HIR+"========================================================================"+NOR+"\n");
    write("��ӭʹ�����������۰壡\n");

write(HIR+"========================================================================"+NOR+"\n");
    for(i=0; i<sizeof(news); i++)   {
       if( !mapp(last_read_time) )  last_read = 0;
       else if( undefinedp(last_read_time[news[i]["id"]]) ) last_read = 0;
       else   last_read = last_read_time[news[i]["id"]];
       msg = sprintf("%2s [%2d]  %4d    %-36s   %14s\n",
         ( news[i]["time"] > last_read ? "N" : " "),
         i+1, sizeof(news[i]["index"]), news[i]["name"], news[i]["id"]);
       write(msg); 
    }
    write("\n��ѡ��Ҫ�Ķ��������飺(q �˳� l ���� �������)");
    input_to("enter_group");
    return 1;
}


int do_cpbboard(string arg)
{
    string  bb, bb_file, newsgroup;
    mapping *news, *notes, note;
    int     i, j, k;

    if( !arg )
	     return notify_fail("ָ���ʽ��cpbboard b_board newsgroup\n");
    
    if( sscanf(arg, "%s %s", bb, newsgroup) != 2 )
		return notify_fail("ָ���ʽ��cpbboard b_board newsgroup\n");
	
    bb_file = "/obj/board/" + bb;			
    if( file_size(bb_file+".c") <= 0 ) 
       return notify_fail("�Ҳ��� " + bb_file + ".c ����ļ���\n");
    
    news = query("news"); 
	if( !pointerp(news) || !sizeof(news) )
	   return 0;
	  
	k=-1;    
	for(i=0; i<sizeof(news); i++)   {
	   if( news[i]["id"] ==  newsgroup )  {
	      k = i;
	      break;
	   }
	} 
	if(k == -1)
	   return notify_fail("û�� "+ newsgroup + " ��������顣\n");
	   
    notes = bb_file->query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
	   return 0;
    
    for(j=0; j<sizeof(notes); j++)  {
       note = allocate_mapping(7);
       note["title"] = notes[j]["title"];
       note["author"] = notes[j]["author"];
       note["time"] = notes[j]["time"];
       note["reply"] = "f";
       note["next"] = 0;
       note["used"] = 0;
       note["msg"] = notes[j]["msg"];
       
       news[k]["index"] += ({ note });
    }
    
    set("news", news);
    tell_object(this_player(), "������ϣ�\n");
    
    save();
    return 1;
}

void do_startmore(string cmd, string *text, int line, object ob, int idx, int sidx)
{
    int i,j;

    switch(cmd) {
        case "":
            for(i=line + 23; line<sizeof(text) && line<i; line++)
                write(text[line] + "\n");
            if( line>=sizeof(text) )  { 
	        write("\n(q �˳�)");
	        input_to("inside_group", ob, idx, sidx);
		return;
            }
            break;
        case "b":
            line = line - 46;
            if(line<-22) return;
            for(i=line + 23; line < i;line++)
               write(text[line]+"\n");
            break;
        case "q":
	    write("\n(q �˳�)");
	    input_to("inside_group", ob, idx, sidx);
            return;
    }
    printf("== δ����� " HIY "%d%%" NOR " == (ENTER ������һҳ��q �뿪��b ǰһҳ)",
        (line*100/sizeof(text)) );
    input_to("do_startmore", text, line, ob, idx, sidx);

}
