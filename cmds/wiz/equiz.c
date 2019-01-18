 //
// edquiz.c
// writed by stey sanjie-lib

inherit F_CLEAN_UP;

string k;
int main(object me, string arg)
{
        int i;
        mapping quizz;
        string str;

        if (! SECURITY_D->valid_grant(me, "(immortal)"))
                return 0;

        seteuid(getuid());

        if (! arg) return notify_fail("��Ҫ����ʲô question��\n");


        if (sscanf(arg, "-c %d", i))
        {
                if (i<0 || i>=(QUIZ_D->sizeof_quiz()))
                return notify_fail("û������⣬�������ֳ��������Ŀ��\n");

                quizz=QUIZ_D->query_quiz(i);
                if (quizz==0 ) return notify_fail("û������⣬�������ֳ��������Ŀ��\n");
                write("��"+i+"��������:  "+quizz["type"]+"\n");
                write("��"+i+"��������:  "+quizz["data"]+"\n");
                write("��"+i+"�����:  "+quizz["answer"]+"\n");
         return 1;
        }
         if (sscanf(arg, "-cut %d", i))
        {
                if (i<0 || i>=(QUIZ_D->sizeof_quiz()))
                return notify_fail("û������⣬�������ֳ��������Ŀ��\n");

                quizz=QUIZ_D->query_quiz(i);
                if (quizz==0 ) return notify_fail("û������⣬�������ֳ��������Ŀ��\n");
                write("��"+i+"��������:  "+quizz["type"]+"\n");
                write("��"+i+"��������:  "+quizz["data"]+"\n");
                write("��"+i+"�����:  "+quizz["answer"]+"\n");
                if(QUIZ_D->delete_quiz(i))      write("cut ok\n");
         return 1;
        }
         if (sscanf(arg, "-m %d", i))
         {
                if (i<0 || i>=(QUIZ_D->sizeof_quiz()))
                return notify_fail("û������⣬�������ֳ��������Ŀ��\n");
                quizz=QUIZ_D->query_quiz(i);
                if (quizz==0 ) return notify_fail("û������⣬�������ֳ��������Ŀ��\n");
                write("��"+i+"����ԭ����:  "+quizz["type"]+"\n");
                write("��"+i+"����ԭ����:  "+quizz["data"]+"\n");
                write("��"+i+"����ԭ��:  "+quizz["answer"]+"\n");
                write("��"+i+"��������޸ģ�\n");
                write("��� ��"+i+"���⡪�����������ͣ�(�����������ʷ�⣬��������ʷ������Ϊ��)��\n->");
                k="m";
                log_file("cmds/edquiz", sprintf("%s(%s) modify quiz %s on %s.\n",
                 me->name(1), geteuid(me), arg, ctime(time()) ) );
                input_to("get_type", i,k);
                return 1;
           }

        if (arg == "-add")
           {

          i=QUIZ_D->sizeof_quiz();
          k="add";

          log_file("cmds/edquiz", sprintf("%s(%s) modify quiz %s on %s.\n",
                 me->name(1), geteuid(me), arg, ctime(time()) ) );
          write("��� ��"+(i+1)+"���⡪�����������ͣ�(�����������ʷ�⣬�����롰��ʷ��_������Ϊ��)��\n->");
           i++;
          input_to("get_type", i,k);

          return 1;
            }
        return notify_fail("��Ҫ����ʲô question��\n");
}

int get_type(string msg,int i,string k)
{
          mapping pattern;
          int j,m,ppl;
           pattern=([]);
/*
        if(CHINESE_D->is_chinese(msg) !=1 && strlen(msg)> 24)
                {
                 write("�����������ģ��������ͣ�\n->");
                 input_to("get_type", i,k);
                  return 1;
                }
*/
        
        if(msg=="q")   return 1;
         
         j=strlen(msg);
         for(m=0;m<j;m+=2){
                     if (msg[m..m]==" ")  {ppl++;continue;}          
                     if (msg[m+1..m+1]==" ")  {ppl++;continue;}  
                          }
         if(ppl>=1)
                     {
                       write("������������м���˿ո񣬡�\n�����������ģ����������������ͣ�\n->");
                        input_to("get_type", i,pattern,k);
                       return 1;
                      } 
        
        pattern["type"]=msg;
        write("��� ��"+i+"���⡪��������𰸣�\n->");
        input_to("get_answer", i,pattern,k);
        return 1;
}
int get_answer(string msg,int i, mapping pattern,string k )
{

         int j,m,ppl;
         if(msg=="q")   return 1; 
         
         if(strlen(msg)<1)
                {
                write("\n->");
                input_to("get_answer", i,pattern);
               
               return 1; }
          
          j=strlen(msg);  
          ppl=0;
         for(m=0;m<j;m+=2){
                     if (msg[m..m]==" ")  {ppl++;continue;}          
                     if (msg[m+1..m+1]==" ")  {ppl++;continue;}  
                          }
         if(ppl>=1)
                     {
                       write("������������м���˿ո�\n�����������ģ�������������𰸣�\n->");
                        input_to("get_answer", i,pattern,k);
                       return 1;
                      } 
 
        if(strlen(msg)<1)
                {
                write("�����������̫�̿���������ᡣ\n->");
                input_to("get_answer", i,pattern);
                }
        pattern["answer"]=msg;
        write("��� ��"+i+"���⡪���������ݣ�\n->");
        input_to("get_data", i,pattern,k);
        return 1;
}

int get_data(string msg,int i, mapping pattern ,string k)
{
        int m,j,ppl;
         if(msg=="q")   return 1;
         if( msg[j..j]==" " )
                {write("����������ֺ�����пո�\n�����������ģ�������������𰸣�\n->");
                 input_to("get_data", i,pattern,k);
                 return 1;}
        if((j=strlen(msg))<10)
                {
                write("�����������̫�̿���������ᡣ\n�����������ģ����������������ݣ�\n->");
                input_to("get_data", i,pattern,k);
                  return 1; }
        ppl=0;
         for(m=0;m<j;m+=2){
/*
                     if (msg[m] < 176 || msg[m] > 247)  { ppl++;continue;}
                     if (msg[m+1] < 161 || msg[m] > 254) { ppl++;continue;}
                     if (msg[m] == 215 && msg[m+1] > 249) {ppl++;continue;}
*/  
                     if (msg[m..m]==" ")  {ppl++;continue;}          
                     if (msg[m+1..m+1]==" ")  {ppl++;continue;}  
                          }
         if(ppl>=1)
                     {
                       write("������������м��е��ֽ��ִ����ߴ��˿ո��뱣��˫�ֽڽṹ�����������롣\n�����������ģ����������������ݣ�\n->");
                       input_to("get_data", i,pattern,k);
                       return 1;
                      }
        pattern["data"]=msg;
        write("\n��"+i+"��������Ϊ��"+pattern["type"]);
        write("\n��"+i+"�����Ϊ��"+pattern["answer"]);
        write("\n��"+i+"��������Ϊ��"+pattern["data"]);
        write("\n�����ȷ���޴�����yes,�����޸�����no�����ϸ���󣬷�ֹ���\n");
        input_to("get_comfirm", i,pattern,k);
        return 1;

}
//137  int get_comfirm(string msg,int i, mapping pattern ,string k)
int get_comfirm(string msg,int i, mapping pattern)
{
                if(msg=="no")
                {
                        write("��� ��"+i+"���⡪���������ͣ�\n->");
                        input_to("get_type", i,k);
                        return 1;
                }
              if(msg=="yes")
              {

                if( k=="add")
                {
                QUIZ_D->add_quiz(pattern);
                write("quiz ���ӽ�����\n");
                return 1;
                }
                if( k=="m")
                {
                QUIZ_D->set_quiz(i,pattern);
                write("quiz �޸Ľ�����\n");

                return 1; }
                return 1;
               }
        write("\n�����ȷ���޴�����yes,�����޸�����no\n");
        input_to("get_comfirm",i,pattern,k);
        return 1;
}


int help(object me)
{
write(@HELP
ָ���ʽ : edquiz [-add]                  (����)
          edquiz [-c|-m|-cut] <NO.>     (�鿴|�޸�|ɾ��)
          ����ʱ��qȡ��
���ָ������޸ģ�ɾ�� ���NO.x�� ���г������ݡ�
-add ���� ������ �������һ�⡣
HELP );
    return 1;
}




