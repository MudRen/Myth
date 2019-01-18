// abandon.c
// modified by Tree

inherit F_CLEAN_UP;

// mon@xyj 10/15/98
void do_abandon(string yn, object me, string arg, int num, string flag);

int main(object me, string arg)
{
    mapping skills;
    string name, flag="";
    int num;

        if( !arg || arg=="" ) return notify_fail("��Ҫ������һ��ܣ�\n");

    if (sscanf(arg,"%s %d",name,num)!=2) 
       if(sscanf(arg,"%s",name)==1) flag="all";
       else  return notify_fail("abandon|fangqi <skillname> <number>\n");
  
        skills=me->query_skills();

    if((string)name=="all")
      {
            if(flag=="all") write("��ȷ��Ҫ�������еļ���ô��(y/n)");
            else write("��ȷ��Ҫ��������С��"+chinese_number(num)+"���ļ���ô��(y/n)");
            input_to("do_abandon_all",me,num,flag);
            return 1;
      }

        if( !skills || undefinedp(skills[name]) )
            return notify_fail("�㲢û��ѧ������ܡ�\n");

    if (num<0)
       return notify_fail("�����������ΰѣ�\n");

        if((int)skills[name]>=10) {
            write("��ȷ��Ҫ����"+to_chinese(name)+
                    "��(y/n)");
            input_to("do_abandon",me,name,num,flag);
        } else
            do_abandon("yes",me,name,num,flag);
        
        return 1;
}

void do_abandon(string yn, object me, string arg, int num, string flag)
{
    int level;
     if(!me) return;

     if(!yn) {
         write("ʲô��\n");
         return;
     }

     if(yn[0]=='y' || yn[0]=='Y' ) {

      level=me->query_skill(arg,1);
      if((flag=="all")||level==0)
        {
        if( !me->delete_skill(arg) ) 
          {
                    write("��û��ѧ������ܡ�\n");
                    return;
              }
         write("�������"+ chinese_number(level)+ "����" + to_chinese(arg) + "��\n");
         return;
         }
      else {
      if (!level) 
      {
        write("û������ܡ�\n");
        return;
      }
      if (level>num) me->set_skill(arg,level-num);
      else      if( !me->delete_skill(arg) ) {
                write("��û��ѧ������ܡ�\n");
                return;
           }}

        write("�������"+ chinese_number(level>num?num:level)+ "����" + to_chinese(arg) + "��\n");
        
        if(MISC_D->random_capture(me,8000,0)) return;

        return;
     } else {
         write("�������������ܡ�\n");
         return;
     }
}

void do_abandon_all(string yn, object me, int num, string flag)
{
     int level,i;
     mapping skills;
     string *sname;
     if(!me) return;

     if(!yn) {
         write("ʲô��\n");
         return;
     }

     if(yn[0]=='y' || yn[0]=='Y' ) {
        skills = me->query_skills();
        sname  = sort_array( keys(skills), (: strcmp :) );
        for (i=0;i<sizeof(sname) ;i++ )
        {
          level = me->query_skill(sname[i],1);
          if(flag=="all") 
           {
             write("�������"+chinese_number(level)+"����"+to_chinese(sname[i])+"��\n");
             me->delete_skill(sname[i]);
           }
          else if(level<num) 
           {
             write("�������"+chinese_number(level)+"����"+to_chinese(sname[i])+"��\n");
             me->delete_skill(sname[i]);
           }
        }
        return;       
     } else {
         write("�������������ܡ�\n");
         return;
     }
}

int help()
{
        write(@TEXT
ָ���ʽ��abandon|fangqi <��������> <����>

���ָ��ʹ�õĳ���ͨ��������ɾ��һЩ����С�ġ��������ļ��ܣ�������Ǽ�����
��������ʱ������������ĸ��ֶ�����ս����ѧϰ�������Щ���ܻ���Ϊ�㾭����ʹ
�ö���������ļ����б��У��������ͱ��뻨��һЩ����ȥ����ס����ѧ����һ��
��Ȼ�����˵����ʸ��в�ͬ�����Ըߵ����ܹ�ѧϰ��༼�ܶ���Ϊ��Ŷ��յĲ��ӣ�
���Խϲ���˾�ֻ��ר����ض�����ܣ������ѧ�ļ�������̫�࣬�����������
����ᷢ�������ѧϰ�ٶȽ���ֻѧ���ּ��ܵ�����������Խ�࣬ѧϰЧ���������
��Խ���أ��������ξ�����һ��ѧ��ͬʱѡ��̫��ѧ�֣���Ȼ����Ȼ����ƾ�����˵�
��־������ȥ�������⽫��໨������౦���ʱ�䡣

��ʽ�� 
fangqi <��������> <����>  ����ָ�������ļ��� 
fangqi <��������> ����ָ�����ܣ�ȫ���� 
fangqi all  �������м��ܣ��б�Ҫô���� 
fangqi all <����> ��������С��ָ������ļ��� 

                                       Tree�޶�
TEXT
        );
        return 1;
}

